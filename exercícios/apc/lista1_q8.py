def mediana_e_mais_proximo_media_e_pos(lista):
    new_list = lista[:]
    new_list.sort()
    tam = len(new_list)
    if tam > 0:
        if tam % 2 == 0:
            mediana = (new_list[int(tam/2)] + new_list[int((tam/2) - 1)])/2
        else:
            mediana = new_list[int(tam/2)]
        media = sum(new_list)/tam
        delta = abs(new_list[0] - media)
        prox_media = new_list[0]
        for i in lista:
            if abs(i - media) < delta:
                delta = abs(i - media)    
                prox_media = i
        return [mediana, prox_media, lista.index(prox_media)]
    return [None, None, None]






lista = [1, 2, 3, 4]
print(mediana_e_mais_proximo_media_e_pos(lista))
lista = [1, 1, 1, 1, 1, 1, 1, 50, 43, 0]
print(mediana_e_mais_proximo_media_e_pos(lista))
lista = []
print(mediana_e_mais_proximo_media_e_pos(lista))
lista = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
print(mediana_e_mais_proximo_media_e_pos(lista))
lista = [123, 486, 159, 321, 357, 753, 125, 652, 111, 987, 987]
print(mediana_e_mais_proximo_media_e_pos(lista))