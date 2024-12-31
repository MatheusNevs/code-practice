def hexadecimal(number):
    eq = {10: 'A', 11: 'B', 12: 'C', 13 : 'D', 14: 'E', 15: 'F'}
    hexa = ''
    if number == 0:
        return '00'
    while number > 0:
        if number % 16 <= 9:
            hexa += str(number % 16)
        else:
            hexa += eq.get(number%16)
        number = number // 16
    return hexa[::-1]



name , *rgb = input().split(', ')
hexa = ''

for i in rgb:
    code = hexadecimal(int(i))
    hexa += code[-2:]

hexa = '#' + hexa.replace('x', '0')

for x in hexa:
        if not x.isnumeric():
            hexa = hexa.replace(x,x.upper())

print(f'{name}, {hexa}')