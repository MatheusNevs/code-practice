while True:
    try:
        njogadores, nempresarios, nequipes = [int(x) for x in input().split()]
        jogadores_de_empresarios = []
        empresarios_com_potencial = []
        jogadores = [int(x) for x in input().split()]

        for _ in range(0, len(input().split())):
            jogadores_de_empresarios.append([int(x) for x in input().split()])

        for idx, jogadores_de_empresario in enumerate(jogadores_de_empresarios):
            equipe_de_jogadores = []
            for id, jogador_de_empresario in enumerate(jogadores_de_empresario):
                if id == 0:
                    equipe_de_jogadores.append(jogadores[jogador_de_empresario - 1])
                else:
                    if jogadores[jogador_de_empresario - 1] not in equipe_de_jogadores:
                        equipe_de_jogadores.append(jogadores[jogador_de_empresario - 1])
            if len(equipe_de_jogadores) == nequipes:
                empresarios_com_potencial.append(idx + 1)

        empresarios_com_potencial.sort()
        if len(empresarios_com_potencial) > 0:
            print(*empresarios_com_potencial, sep = ' ')
        else:
            print(-1)
    except EOFError:
        break