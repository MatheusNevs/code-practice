while True:
    try:
        fileiras = []
        distancia_maior = 0
        m,n = [int(x) for x in input().split()]
        for i in range(0,m):
            fileiras.append([int(x) for x in input().split()])
        for fileira in fileiras:
            distancia_r = distancia_l = 0
            for p, c in enumerate(fileira):
                if c == 0:
                    if 1 in fileira[:p+1]:
                        pos_um = p
                        while pos_um >= 0 and pos_um < len(fileira):
                            if fileira[pos_um] == 1:
                                break
                            pos_um -= 1
                            distancia_l = abs(pos_um - p)
                    else:
                        distancia_l = 10000
                    if 1 in fileira[p:]:
                        pos_um = p
                        while pos_um >= 0 and pos_um < len(fileira):
                            if fileira[pos_um] == 1:
                                break
                            pos_um += 1
                            distancia_r = abs(pos_um - p)
                    else:
                        distancia_r = 10000
                if min(distancia_l, distancia_r) > distancia_maior:
                    distancia_maior = min(distancia_l, distancia_r)
        print(distancia_maior)
    except EOFError:
        break