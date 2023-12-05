arquivo = input()

with open(arquivo, 'r') as data:
    linhas = [x.split(',') for x in data.readlines()]
for linha in linhas:
    print(linha[1])