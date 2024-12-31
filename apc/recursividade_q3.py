def controle(comprimidos, inicio):
    inicio += 1
    if inicio == comprimidos:
        print(f"Parabens Julie! Voce tomou todos os {inicio} comprimidos")
        return
    else:
        print(f'Voce ja tomou {inicio} comprimidos, restam {comprimidos - inicio}.')
    controle(comprimidos, inicio)
