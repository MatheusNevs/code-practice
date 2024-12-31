def ajustar_string(string):
    nova_string = ''
    for k, c in enumerate(string):
        nova_string += c
        
        if k < len(string) + 1 and c.isnumeric() == False and string[k+1].isnumeric() == False:
            nova_string += "1"
    return nova_string


def codificar(string):
    nova_string = ajustar_string(string)
    multiplicador = 0
    ans = ''
    letra = ''
    for caracter in nova_string:
        if caracter.isnumeric() == False:
            ans += letra*int(multiplicador)
            letra = caracter
            multiplicador = 0
        else:
            multiplicador = str(multiplicador) + caracter
    ans += letra*int(multiplicador)
    return ans


caminho = input()

with open(caminho, 'r') as data:
    linhas =[x.replace('\n', '') for x in data.readlines()]
for linha in linhas:
    print(codificar(linha))