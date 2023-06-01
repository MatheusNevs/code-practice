mensagem = input().split('=')
left = mensagem[0]
right = mensagem[1]
try:
    isoled = int(left)
    variable = right.split('+')
except:
    variable = left.split('+')
    isoled = int(right)

for c in variable:
    if c.isnumeric():
        isoled += -(int(c))
    else:
        letter = c

print(f'{letter} = {isoled}')