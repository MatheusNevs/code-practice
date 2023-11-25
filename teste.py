def percorrerArvore(raiz, n = 0):
    e = n
    d = n
    if raiz[1]:
        e += 1
        percorrerArvore(raiz[1], e)
    else:
        alturas.append(e)
    if raiz[2]:
        d += 1
        percorrerArvore(raiz[2], d)
    else:
        alturas.append(d)

def altura(raiz):
    if raiz != None:
        global alturas
        alturas = []
        percorrerArvore(raiz)
        return max(alturas) + 1
    else:
        return 0
