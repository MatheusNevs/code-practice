def corrida(voltas_restantes, pneu_restantes, voltas_pneu):
    if pneu_restantes == 0 and voltas_restantes != 0:
        print(f'Faltam {voltas_restantes} voltas, hora de trocar os pneus.')
        pneu_restantes = voltas_pneu
    if voltas_restantes == 0:
        print('A corrida chegou ao fim.')
        return
    corrida(voltas_restantes - 1, pneu_restantes - 1, voltas_pneu)


corrida(30,5,5)
print()
corrida(8,10,10)
print()
corrida(10, 8, 8)