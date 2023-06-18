def fibonacci(n):
    if n <= 0:
        return 0
    elif n == 1:
        return 1
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)

def fibonacci_callings(number):
    lista = [0]*(number + 1)
    x = 0
    for i in range(0, number + 1):
        x += 1
        if number - i != 0:
            lista[number - i] = fibonacci(i + 1)
    if number > 1:
        lista[0] = lista[2]
    else:
        if number == 0:
            lista[0] = 1
        else:
            lista[0] == 0
    return lista


number = int(input())

print(f'Termo: {fibonacci(number)}')
print('Quantidades:')
for n,x in enumerate(fibonacci_callings(number)):
    print(f'fibonacci({n}) - {x}') 