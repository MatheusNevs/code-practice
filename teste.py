n = int(input())
for c in range(0,n):
    palavra = input()
    nova = ''
    letter = ''
    mult = '0'
    for i in palavra:
        if not i.isnumeric():
            nova += letter * int(mult)
            letter = i
            mult = '0' 
        else: 
            mult += i
    nova += letter * int(mult)
print(nova)
        
        
    


            