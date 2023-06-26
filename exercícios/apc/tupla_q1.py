def convert(list):
    dicionario = {}
    for chave, *valor in list:
        if chave in dicionario.keys():
            dicionario[chave].append(*valor)
        else:
            dicionario[chave] = valor
    return dicionario

l = [(3, 91), (4, 69), (1, 85), (1, 96), (1, 7), (4, 94)]
resposta = convert(l)
print(resposta)