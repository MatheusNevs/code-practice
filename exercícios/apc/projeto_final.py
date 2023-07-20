def codificar(frase):
    frase_aux = ''
    for c in frase:
        if c.isnumeric():
            frase_aux += '0'
        else:
            frase_aux += c
    return frase_aux


def checar_mt(frase, list1, list2):
    for i in list1:
        if i in frase.lower():
            return list1[0]
    for i in list2:
        if i in frase.lower():
            return list2[0]

def checar_endereco(frase):
    endereco = ''
    cep = 'nao informado'
    
    if 'Rua' in frase:
        endereco = "Rua " + frase[frase.find('Rua') + 4:]
    elif 'Avenida' in frase:
        endereco =  "Avenida " + frase[frase.find('Avenida') + 8:]

    numero = ''
    for c in endereco:
        if c.isnumeric():
            numero += c
        else:
            if numero != '':
                break

    endereco = endereco[:endereco.find(numero) + len(numero)]
    modelo_cep = '00000-000'
    frase_codificada = codificar(frase)
    if modelo_cep in frase_codificada and frase[frase_codificada.find(modelo_cep) + 9].isnumeric() == False:
        cep =  frase[frase_codificada.find(modelo_cep): frase_codificada.find(modelo_cep) + 9]

    return f'Endereco: {endereco}\nCEP: {cep.strip()}'

def checar_area(frase):
    area = 'nao informado'
    if 'metros' in frase or 'm2' in frase:
        frase_aux = frase.split()
        for k, i in enumerate(frase_aux):
            if 'metros' in i:
                area = frase_aux[k - 1]
            if 'm2' in i:
                area = frase_aux[k - 1]
    return f'Area: {area}'

def checar_valor(frase):
    valor = 'nao informado'
    if 'R$' in frase or 'reais' in frase:
        frase_aux = frase.split()
        for k, i in enumerate(frase_aux):
            if 'R$' in i:
                valor = i[2:]
            if 'reais' in i:
                valor = frase_aux[k - 1]
        if valor[-1].isnumeric() == False:
            valor = valor[:-1]
    return f'Valor: {valor}'

def checar_telefone(frase):
    modelo_telefone1 = '00000-0000'
    modelo_telefone2 = '0000-0000'
    telefones = []
    frase_codificada = codificar(frase)
    frase_aux = frase
    if modelo_telefone1 in frase_codificada:
        telefone = frase_aux[frase_codificada.find(modelo_telefone1): frase_codificada.find(modelo_telefone1)+ 10]
        telefones.append(telefone)
        frase_aux = frase_aux.replace(telefone, '')
        frase_codificada = frase_codificada.replace(modelo_telefone1, '')
    if modelo_telefone2 in  frase_codificada:
        telefones.append(frase_aux[frase_codificada.find(modelo_telefone2): frase_codificada.find(modelo_telefone2)+ 9])
    telefones.sort(key = lambda x: frase.find(x))
    telefones = [x.strip() for x in telefones]
    return f"Telefone: {', '.join(telefones)}" if len(telefones) == 1 else f"Telefones: {', '.join(telefones)}"


def checar_responsavel(frase):
    ultima = frase.split('.')[-2].split()
    nome = 'nao informado'
    for k, palavra in enumerate(ultima):
        if palavra[0].isupper():
            if k == 0:
                nome = palavra
            else:
                if ultima[k - 1][0].isupper() == False:
                    nome = palavra
                else:
                    nome += ' ' +palavra
    return f'Responsavel: {nome.replace(",", "").strip()}'


modalidade = [['Aluguel', 'aluguel', 'alugo', 'alugar'], ['Venda', 'venda', 'vendo', 'vender']]
tipo = [['Casa', 'casa'], ['Apartamento', 'apartamento']]

n = 0 
while True:
    try:
        n += 1
        print(f'teste {n}')
        frase = input()
        print(f'Modalidade: {checar_mt(frase, *modalidade)}')
        print(f'Tipo: {checar_mt(frase, *tipo)}')
        print(checar_endereco(frase))
        print(checar_area(frase))
        print(checar_valor(frase))
        print(checar_telefone(frase))
        print(checar_responsavel(frase))
        print()
    except EOFError:
        break

