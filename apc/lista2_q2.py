n = int(input())
idx = int(input())
lista = []
new_list = []
for i in range(0, n):
    lista.append([int(x) for x in input().split()])

lista.sort(key=lambda x: x[idx])

x = soma = indx = 0
for k, i in enumerate(lista):
    if k == 0:
        x = i[idx]
        soma = sum(i)
        indx = k
        new_list.append(i)
    else:
        if i[idx] == x:
            if sum(i) > soma:
                new_list.append(i)
                soma = sum(i)
                indx = k
            else:
                new_list.insert(indx, i)
                soma = sum(i)
                indx = k
        else:
            new_list.append(i)


for i in lista:
    print(*i, sep=" ")

# for i in new_list:
#     print(*i, sep=" ")
