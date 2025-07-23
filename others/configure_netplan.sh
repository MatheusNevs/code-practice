#!/bin/bash

# ==============================================================================
# Script para Automatizar a Configuração de Rede com Netplan
# Projeto: Servidor GigaNuvem
# Descrição: Este script interativo configura duas interfaces de rede agregadas
#            (bond0 e bond1) usando LACP em um servidor Ubuntu 22.04.
# ==============================================================================

# --- Definição de Cores para o Output ---
C_RED='\033[0;31m'
C_GREEN='\033[0;32m'
C_YELLOW='\033[0;33m'
C_BLUE='\033[0;34m'
C_NC='\033[0m' # No Color

# --- Funções de Utilidade ---
function print_info() {
    echo -e "${C_BLUE}[INFO] $1${C_NC}"
}

function print_success() {
    echo -e "${C_GREEN}[SUCESSO] $1${C_NC}"
}

function print_warning() {
    echo -e "${C_YELLOW}[AVISO] $1${C_NC}"
}

function print_error() {
    echo -e "${C_RED}[ERRO] $1${C_NC}"
}

# --- Verificação de Privilégios ---
if [[ $EUID -ne 0 ]]; then
   print_error "Este script precisa ser executado com privilégios de root (sudo)."
   exit 1
fi

# --- Início do Script ---
clear
print_info "======================================================"
print_info " Assistente de Configuração de Rede GigaNuvem "
print_info "======================================================"
echo

# --- Coleta de Informações do Usuário ---
print_info "Por favor, forneça os detalhes para a configuração da rede."
echo

# Coleta para bond0 (Rede de Acesso)
print_info "--- Configuração da Interface bond0 (Rede de Acesso) ---"
read -p "Nome da 1ª interface física para bond0 (ex: eno1): " BOND0_IF1
read -p "Nome da 2ª interface física para bond0 (ex: enp1s0f0): " BOND0_IF2
read -p "Endereço IP para bond0 (ex: 10.1.0.1/24): " BOND0_IP
read -p "Gateway para bond0 (ex: 10.1.0.0): " BOND0_GW
read -p "Servidor DNS para bond0 (ex: 10.1.0.100): " BOND0_DNS
echo

# Coleta para bond1 (Rede de Cluster)
print_info "--- Configuração da Interface bond1 (Rede de Cluster) ---"
read -p "Nome da 1ª interface física para bond1 (ex: enp4s0): " BOND1_IF1
read -p "Nome da 2ª interface física para bond1 (ex: enp1s0f1): " BOND1_IF2
read -p "Endereço IP para bond1 (ex: 10.2.0.1/24): " BOND1_IP
read -p "Gateway para bond1 (ex: 10.2.0.0): " BOND1_GW
echo

# --- Confirmação das Informações ---
print_info "--- Revisão das Configurações ---"
echo -e "bond0 (Acesso):"
echo -e "  Interfaces: ${C_YELLOW}${BOND0_IF1}, ${BOND0_IF2}${C_NC}"
echo -e "  IP: ${C_YELLOW}${BOND0_IP}${C_NC}"
echo -e "  Gateway: ${C_YELLOW}${BOND0_GW}${C_NC}"
echo -e "  DNS: ${C_YELLOW}${BOND0_DNS}${C_NC}"
echo
echo -e "bond1 (Cluster):"
echo -e "  Interfaces: ${C_YELLOW}${BOND1_IF1}, ${BOND1_IF2}${C_NC}"
echo -e "  IP: ${C_YELLOW}${BOND1_IP}${C_NC}"
echo -e "  Gateway: ${C_YELLOW}${BOND1_GW}${C_NC}"
echo

read -p "As informações estão corretas? (s/n): " CONFIRM
if [[ "$CONFIRM" != "s" && "$CONFIRM" != "S" ]]; then
    print_error "Operação cancelada pelo usuário."
    exit 0
fi

# --- Geração do Arquivo de Configuração Netplan ---
NETPLAN_FILE="/etc/netplan/00-giganuvem-automated.yaml"
print_info "Gerando o arquivo de configuração em ${NETPLAN_FILE}..."

# Usando um 'heredoc' para escrever o arquivo YAML
cat > "$NETPLAN_FILE" << EOF
# Arquivo de configuração de rede gerado automaticamente pelo script GigaNuvem
network:
  version: 2
  renderer: networkd
  ethernets:
    ${BOND0_IF1}:
      dhcp4: no
      dhcp6: no
    ${BOND0_IF2}:
      dhcp4: no
      dhcp6: no
    ${BOND1_IF1}:
      dhcp4: no
      dhcp6: no
    ${BOND1_IF2}:
      dhcp4: no
      dhcp6: no
  bonds:
    bond0:
      interfaces: [${BOND0_IF1}, ${BOND0_IF2}]
      addresses: [${BOND0_IP}]
      gateway4: ${BOND0_GW}
      nameservers:
        addresses: [${BOND0_DNS}]
      parameters:
        mode: 802.3ad
        mii-monitor-interval: 100
        lacp-rate: fast
        transmit-hash-policy: layer3+4
    bond1:
      interfaces: [${BOND1_IF1}, ${BOND1_IF2}]
      addresses: [${BOND1_IP}]
      gateway4: ${BOND1_GW}
      parameters:
        mode: 802.3ad
        mii-monitor-interval: 100
        lacp-rate: fast
        transmit-hash-policy: layer3+4
EOF

if [ $? -eq 0 ]; then
    print_success "Arquivo de configuração gerado com sucesso."
else
    print_error "Falha ao gerar o arquivo de configuração."
    exit 1
fi
echo

# --- Aplicação da Configuração ---
print_warning "A aplicação da nova configuração de rede pode causar uma breve interrupção na conectividade."
read -p "Pressione [Enter] para continuar e aplicar as configurações..."

print_info "Executando 'netplan generate'..."
netplan generate
if [ $? -ne 0 ]; then
    print_error "Falha no 'netplan generate'. Verifique o arquivo de configuração em ${NETPLAN_FILE}."
    exit 1
fi

print_info "Executando 'netplan apply'..."
netplan apply
if [ $? -ne 0 ]; then
    print_error "Falha no 'netplan apply'. A configuração de rede pode estar instável."
    exit 1
fi

print_success "Configuração de rede aplicada com sucesso!"
echo

# --- Validação e Testes ---
print_info "Iniciando testes de validação..."
sleep 2 # Pausa para a rede estabilizar

# 1. Verificar Interfaces e IPs
print_info "--- 1. Verificando Interfaces e IPs (ip addr show) ---"
ip addr show | grep -E "bond0:|bond1:" -A 2
echo

# 2. Verificar Status do Bonding
print_info "--- 2. Verificando Status do bond0 (/proc/net/bonding/bond0) ---"
cat /proc/net/bonding/bond0
echo
print_info "--- 2. Verificando Status do bond1 (/proc/net/bonding/bond1) ---"
cat /proc/net/bonding/bond1
echo

# 3. Verificar Tabela de Roteamento
print_info "--- 3. Verificando Tabela de Roteamento (ip route) ---"
ip route | grep default
echo

# 4. Testar Conectividade
print_info "--- 4. Testando Conectividade ---"
print_info "Pingando o gateway (${BOND0_GW})..."
ping -c 4 ${BOND0_GW}
if [ $? -eq 0 ]; then
    print_success "Gateway acessível."
else
    print_error "Não foi possível alcançar o gateway."
fi
echo

print_info "Pingando um IP externo (8.8.8.8) para testar DNS e rota..."
ping -c 4 8.8.8.8
if [ $? -eq 0 ]; then
    print_success "Conectividade com a internet estabelecida."
else
    print_error "Falha na comunicação com a internet. Verifique o gateway e o DNS."
fi
echo

print_info "======================================================"
print_success " Verificação concluída! "
print_info "======================================================"

exit 0
