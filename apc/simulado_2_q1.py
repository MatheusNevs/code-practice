# canoa = 60 
# barco = 105
# voadeira = 140

tickets, kind = input().split()
kinds = {'C': 60, 'B': 105, 'V': 120}
auto = {'C': 'canoa', 'B': 'barco', 'V': 'voadeira'}
price = int(tickets)*int(kinds.get(kind))
print(f'Para transportar {tickets} passageiros de {auto.get(kind)} saíra R$ {price:.2f}')