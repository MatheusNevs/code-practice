def decimal2bin(n):
    code = bin(n)
    code = code[2:]
    code = code.zfill(8)
    return str(code)

def reverse(s):
    rev = s[::-1]
    return rev

def decodifica(codeBinario, codeUnario):
    decimal = len(codeUnario)
    if decimal % 2 == 0:
        zero=codeBinario[decimal-1]
        for i in codeBinario:
            if i != zero:
                um = i
                break
    else:
        um = codeBinario[decimal-1]
        for i in codeBinario:
            if i != um:
                zero = i
                break
    return zero, um
    
def converte2alien(zero, um, code):
    decimal = int(code)
    binário = decimal2bin(decimal)
    alien = ""
    for i in binário:
        if i == "0":
            alien += zero
        elif i == "1":
            alien += um
    return alien

def converte2decimal(zero, um, code):
    decimal = "0b"
    for i in code:
        if i == zero:
            decimal += "0"
        elif i == um:
            decimal += "1"
    return int(decimal, 2)

def isBigEndian(códigoBinárioAlien, códigoUnárioAlien):
    decimal = len(códigoUnárioAlien)
    if decimal % 2 == 0:
        zero = códigoUnárioAlien[len(códigoBinárioAlien)-1]
        for i in códigoUnárioAlien:
            if i != zero:
                um = i
                break
    else:
        um = códigoUnárioAlien[len(códigoBinárioAlien)-1]
        for i in códigoUnárioAlien:
            if i != um:
                zero = i
                break
    binario = "0b"
    for i in códigoBinárioAlien:
        if i == zero:
            binario += "0"
        elif i == um:
            binario += "1"
    if int(binario, 2) != decimal:
        return True
    else:
        return False   
    
def BigEndian2LittleEndian(códigoBinárioAlien):
    return reverse(códigoBinárioAlien)

def LittleEndian2BigEndian(códigoBinárioAlien):
    return reverse(códigoBinárioAlien)
    
códigoBinário, códigoUnário = input().split()
n = len(códigoUnário)
bigEndian = isBigEndian(códigoBinário, códigoUnário)
if bigEndian:
    códigoBinário = BigEndian2LittleEndian(códigoBinário)
zero, um = decodifica(códigoBinário, códigoUnário)
for i in range(n):
    code = input()
    if code.isdigit():
        if bigEndian:
            print(LittleEndian2BigEndian(converte2alien(zero, um, code)))
        else:
            print(converte2alien(zero, um, code))
    else:
        if bigEndian:
            code = BigEndian2LittleEndian(code)
            print(converte2decimal(zero, um, code))
        else:
            print(converte2decimal(zero, um, code))
        
        
    


            