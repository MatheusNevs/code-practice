letras = {'d':0, 't': 0, 'v':0}
frase = input()

for letra in letras.keys():
    if frase.count(letra) > 0:
        letras[letra] += frase.count(letra)

print(*[f'{letra} {quantidade}' for letra, quantidade in letras.items() if quantidade > 0], sep = '\n')