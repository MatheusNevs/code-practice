def triangulo(x, size = int,aux = 1):
    if aux <= size:
        c = '+'*aux
        print(' '*(x) + f'{c:^{size}}' )
        aux += 2
        triangulo(x, size, aux = aux)

triangulo(0, 5)
triangulo(3, 7)
triangulo(6, 5)
triangulo(6, 5)
