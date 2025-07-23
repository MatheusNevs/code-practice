# 📄 Readme - Script de Automação de Rede GigaNuvem

## 1. Visão Geral

Este repositório contém um script Bash (`configure_netplan.sh`) projetado para automatizar e simplificar a configuração de interfaces de rede agregadas (bonding/LACP) em um servidor rodando Ubuntu 22.04.

O script é interativo e guia o usuário durante o fornecimento dos nomes das interfaces e detalhes de endereçamento IP, gerando o arquivo de configuração do Netplan, aplicando-o e executando testes de validação.

---

## 2. Pré-requisitos

- **Sistema Operacional:** Ubuntu 22.04 (ou compatível com Netplan)
- **Software:** `netplan.io` instalado (padrão no Ubuntu Server)
- **Hardware:** Pelo menos 4 interfaces de rede físicas disponíveis
- **Rede:** Switch configurado para suportar LACP (802.3ad) nas portas correspondentes

---

## 3. Como Instalar e Executar

**Tornar o Script Executável:**

```bash
chmod +x configure_netplan.sh
```

**Executar o Script:**

O script requer privilégios de superusuário para criar arquivos em `/etc/netplan/` e executar comandos Netplan. Execute com:

```bash
sudo ./configure_netplan.sh
```

---

## 4. O que o Script Faz

Ao ser executado, o script realiza:

1. **Verificação de Privilégios:** Confirma execução com sudo.
2. **Coleta de Dados:** Solicita interativamente:

- Nomes das duas interfaces físicas para a `bond0` (Rede de Acesso)
- Endereço IP, Gateway e DNS para a `bond0`
- Nomes das duas interfaces físicas para a `bond1` (Rede de Cluster)
- Endereço IP e Gateway para a `bond1`

3. **Confirmação:** Exibe resumo das informações e pede confirmação.
4. **Geração do Arquivo:** Cria `/etc/netplan/00-giganuvem-automated.yaml` com os dados fornecidos.
5. **Aplicação da Configuração:** Executa `sudo netplan generate` e `sudo netplan apply`.
6. **Validação e Testes:** Automaticamente:

- Mostra os IPs das novas interfaces `bond0` e `bond1`
- Exibe status detalhado das agregações, modo LACP e estado das interfaces "escravas"
- Verifica a tabela de roteamento
- Realiza testes de ping para o gateway e para `8.8.8.8`

---
