msg = input()
for i in msg[::-1]:
    if i.islower():
        print(i, end = '')
print()