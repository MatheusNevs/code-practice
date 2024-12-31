names = []
for i in range(0, int(input())):
    names.append(input())
names.sort(reverse= True)
print(*names, sep = '\n')