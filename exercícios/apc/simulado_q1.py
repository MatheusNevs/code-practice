#primeira linha - coordenadas x1, y1, x2, y2 da fazenda
#segunda linha - quantidade de meteoritos
#n linha - coordenadas dos meteoritos

def check_if_in(farm,meteorite):
    x1,y1, x2, y2 = farm
    x,y = meteorite
    if (x >= x1 and x <= x2) and (y <= y1 and y >= y2):
        return True
    return False

tries = 0
while True:
    try:
        tries += 1
        number_of_in = 0
        farm_coords = [int(x) for x in input().split()]
        tests = int(input())
        for i in range(0, tests):
            meteorite_coords = [int(x) for x in input().split()]
            if check_if_in(farm_coords, meteorite_coords):
                number_of_in += 1
        print(f'Teste {tries}')
        print(number_of_in)
    except EOFError:
        break