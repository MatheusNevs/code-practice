while True:
    try:
        lista = []
        n = int(input())
        for i in range(0, n):
            lista.append(input().split())

        x = 0
        for i in range(0, n):
            for j in range(0, n):
                if j == i or j == n - 1 - i:
                    if lista[i][j] != "X":
                        x += 1
                        break
                else:
                    if lista[i][j] == "X":
                        x += 1
                        break

        print(
            "O one piece eh real"
            if x == 0
            else "Talvez o tesouro seja os amigos que fizemos no caminho"
        )
    except EOFError:
        break
