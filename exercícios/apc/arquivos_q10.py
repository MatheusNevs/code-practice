caminho = input()

with open(caminho, 'r') as data:
    conteudo = [x.replace('\n', '') for x in data.readlines()]

linhas = len(conteudo)
colunas = len(conteudo[0])

for n, linha in enumerate(conteudo):
    if 'wally' in linha:
        print(f'{n+1} {linha.find("wally")+1} horizontal')

for n in range(0, colunas):
    coluna = ''
    for linha in conteudo:
        coluna += linha[n]
    if 'wally' in coluna:
        print(f'{coluna.find("wally") + 1} {n+1} vertical')