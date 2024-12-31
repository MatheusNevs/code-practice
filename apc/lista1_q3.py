def paron(list_palavras):
    palavras_pares = []
    for palavra in list_palavras:
        i = 0
        for letra in palavra:
            if letra in 'aeiouAEIOU':
                i += 1
        if i % 2 == 0:
            palavras_pares.append(palavra)
    return palavras_pares
    
print(paron(['Leandro', 'Maristela', 'Bruno', 'Ana', 'Edison', 'Lucas', 'Alexandre', 'Iago']))