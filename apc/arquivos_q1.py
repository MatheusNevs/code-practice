arquivo = input()

with open(arquivo, 'r') as data:
    linhas = data.read().replace('\n', '')
print(eval(linhas))