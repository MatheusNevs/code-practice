while True:
    try:
        corredores = {}
        n = int(input())
        for i in range(0, n):
            produtos = {}
            corredor = input().split()
            for j in range(0, len(corredor), 2):
                if j != len(corredor):
                    produtos[corredor[j]] = corredor[j+1]
            corredores[f'corredor {i + 1}'] = produtos
        numero_corredor = int(input())
        if numero_corredor > n or numero_corredor < 1:
            print('Este corredor não existe no mercado')
        else:
            for i in corredores.keys():
                if str(numero_corredor) in i:
                    print(f'No corredor {numero_corredor} encontramos:')
                    print(*corredores[i].keys(), sep = ', ')
                    media = sum([float(x) for x in corredores[i].values()])/len(corredores[i].values())
                    print(f'E o preço médio é {media:.2f}.')
    except EOFError:
        break