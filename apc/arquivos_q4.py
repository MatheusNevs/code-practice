caminho1, caminho2 = input().split()
vazio = ''
nao_vazio = ''
conteudo_nao_vazio = ''
with open(caminho1, 'r') as data:
    conteudo = data.read()
    if len(conteudo) == 1:
        vazio = caminho1
        nao_vazio = caminho2
    else:
        vazio = caminho2
        nao_vazio = caminho1
        conteudo_nao_vazio = conteudo

if conteudo_nao_vazio == '':
    with open(caminho2, 'r') as data:
        conteudo_nao_vazio = data.read()

print(f'O arquivo {vazio} esta quase vazio, mas o {nao_vazio} nao esta!')
print(conteudo_nao_vazio)
