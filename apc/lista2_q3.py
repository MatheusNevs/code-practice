n,m = [int(x) for x in input().split()]
matriz = []
for _ in range(0,n):
    matriz.append([0]*m)

for _ in range(0, int(input())):
    x,y = [int(z) - 1 for z in input().split()]
    for i in range(0,m):
        matriz[x][i] += 1
    for j in range(0,n):
        if j != x:
            matriz[j][y] += 1

maximo = max([max(linha) for linha in matriz])
soma = 0
for linha in matriz:
    soma += linha.count(maximo)
print(soma)