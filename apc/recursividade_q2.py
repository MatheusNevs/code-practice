def contador(segundos, trava = bool):
    if segundos == 1:
        print("Bomba desativada automaticamente!" if trava else "Seja rápido. Falta 1 segundo\nCabum!!!! Explodiu")
        return
    else:
        if segundos == 5:
            print("Seu tempo está acabando!")
        else:
            print(f'Atenção faltam {segundos} segundos...')
    contador(segundos - 1, trava)


tempo = int(input())
recorde = int(input())

if tempo == 0:
    print("Cabum!!!! Explodiu")
else:
    if recorde >= tempo:
        contador(tempo, trava = True)
    elif recorde < tempo:
        contador(tempo, trava = False)

