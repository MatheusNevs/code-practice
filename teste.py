lista_geral = []
caminho = './log_fís.txt'


def calcular_média(medidas):
    return sum(medidas)/len(medidas)

def calcular_erro_aleatório(medidas):
    xm = calcular_média(medidas)
    n = len(medidas)
    soma = 0
    for x in medidas:
        soma += (x - xm)**2
    return (soma/(n*(n-1)))**(1/2) 

def calcular():
    global lista_geral
    medidas = [float(x)*11.3 for x in input('Medidas a serem calculadas:  ').split()]
    erro_instrumental = float(input('Erro instrumental da medida:   '))
    xmédio = calcular_média(medidas)
    erro_aleatório = calcular_erro_aleatório(medidas)
    erro_experimental = erro_aleatório + erro_instrumental
    lista_geral.append([*medidas, xmédio, erro_instrumental, erro_aleatório, erro_experimental])
    print(f'Xmédio = {xmédio}\nErro aleatório = {erro_aleatório}\nErro experimental = {erro_experimental}')

def mostra_tabela(dados):
    if len(dados) == 0:
        print('Não há dados a serem mostrados')
    else:
        for y in range(0, len(dados[0])):
            for x in dados:
                print(f'  {x[y]:.4f}  ', end = '')
            print('')

def gravar(caminho, dados):
    with open(caminho, 'w') as arquivo:
        for y in range(0, len(dados[0])):
            for x in dados:
                arquivo.write(f'  {x[y]:.4f}  ')
            arquivo.write('\n')

while True:
    print('''[1] Calcular 
[2] Mostrar dados
[3] Sair''')
    opção = int(input())
    if opção == 1:
        calcular()
    if opção == 2:
        mostra_tabela(lista_geral)
    if opção == 3:
        gravar(caminho, lista_geral)
        break
