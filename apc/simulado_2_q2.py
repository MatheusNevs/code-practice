def print_price(fish, price):
    price = f'{float(price):.2f} '
    fish = f' {fish}'
    print('+--------------------+--------------------+')
    print('|' + f'{fish:<20}', end = '')
    print('|' + f'{price:>20}' + '|')

print('''+--------------------+--------------------+
|        peixe       |      preço   R$    |''')

fishes = []
prices = []
fish_info = input().split()
cheapest = fish_info
while fish_info[0] != 'fim':
    fishes.append(fish_info)
    if float(fish_info[1]) < float(cheapest[1]):
        cheapest = fish_info
    fish_info = input().split()

if not fishes:
    print('''+--------------------+--------------------+
|           Hoje não tem peixe            |
+-----------------------------------------+''')
else:
    for fish in fishes:
        print_price(fish[0], fish[1])
    print('+--------------------+--------------------+')
    if len(fishes) > 1:
        print()
        print('''+-----------------------------------------+
|         Cambada de menor preço          |''')
        print_price(cheapest[0], cheapest[1])
        print('+--------------------+--------------------+')