def checar_mt(frase, list1, list2):
    for i in list1:
        if i in frase:
            return list1[0]
    for i in list2:
        if i in frase:
            return list2[0]

def checar_endereco(frase):
    endereco = ''
    cep = ''
    for i in frase.split('.'):
        if 'Rua' in i:
            endereco =  i[i.find('Rua') + 4:]
        elif 'Avenida' in i:
            endereco =  i[i.find('Avenida') + 8:]
    if 'CEP' in endereco:
        cep = endereco[endereco.find('CEP') + 4:]
        return endereco[:endereco.find('CEP') - 2] , cep
    return endereco, 'não informado'


def checar_area(frase):
    



modalidade = [['Aluguel', 'aluguel', 'alugo', 'alugar'], ['Venda', 'venda', 'vendo', 'vender']]
tipo = [['Casa', 'casa'], ['Apartamento', 'apartamento']]

informacoes = ['não informado', 'não informado', 'não informado', 'não informado', 'não informado', 'não informado',
               'não informado', 'não informado']

frase = 'Apartamento disponivel para aluguel na Avenida Sao Carlos, numero 542. 140 metros quadrados, confortavel e espacoso. Falar no numero 99245-1777 com Jose Galdino.'
informacoes[0] = checar_mt(frase, *modalidade)
informacoes[1] = checar_mt(frase, *tipo)
informacoes[2], informacoes[3] = checar_endereco(frase)

print(*informacoes, sep = '\n')