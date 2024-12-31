while True:
    print('Teste')
    try:
        n,m, f = [int(x) for x in input().split()]
        max_pooling = []
        matriz = []
        for _ in range(0,n):
            matriz.append([int(x) for x in input().split()])

        for j in range(0, n, f):
            lista = []
            for i in range(0, m, f):
                if i != m and j != n:
                    lista.append(max([max(matriz[x][i:i+f]) for x in range(j, j+f)]))
            max_pooling.append(lista)

        for linha in max_pooling:
            print(*linha, sep =' ')
    except EOFError:
        break