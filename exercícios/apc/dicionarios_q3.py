lista_de_produtos = input().split()
precos = {}
for i in range(0,len(lista_de_produtos), 2):
    if i != len(lista_de_produtos):
        produto, preco = lista_de_produtos[i], lista_de_produtos[i+1] 
        precos[produto] = preco

pedido = input().split()
custo = 0
for i in range(0, len(pedido), 2):
    if i != len(pedido):
        produto, quantidade = pedido[i], pedido[i+1]
        custo += float(precos.get(produto))*int(quantidade)
print(f'R$ {custo:.2f}')