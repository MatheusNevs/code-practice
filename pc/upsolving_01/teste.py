n = int(input())

numeros = [[i, int(x)] for i, x in enumerate(input().split())]

numeros.sort(key = lambda x : x[1])

i = 0
for idx, value in numeros:
    numeros[i][1] = i + 1
    i += 1

numeros.sort(key = lambda x : x[0]) 

juntar = lambda x : ' '.join([str(y[1]) for y in x])
print(juntar(numeros))