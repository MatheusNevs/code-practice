names = []
for i in range(0, int(input())):
    names.append(input())
impostores = input().split()
for impostor in impostores:
    if impostor in names:
        while impostor in names:
            del(names[names.index(impostor)])
print(*names)