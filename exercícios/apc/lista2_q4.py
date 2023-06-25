
def check(k, quantidade):
    for i in quantidade:
        if i < k:
            print('Nao')
            return False
        return True


n,m, k = [int(x) for x in input().split()]
quantidade_de_produtos = [int(x) for x in input().split()]
produtos_de_mercearias = []
if check(k, quantidade_de_produtos):
    for _ in range(0,n):
        produtos_de_mercearias.append([int(x) for x in input().split()])
    c = 0
    while True:
        cp = 0
        try:
            for x in range(0,n):
                minimo = min(produtos_de_mercearias[x])
                if m >= minimo:
                    m = m - minimo
                    produtos_de_mercearias[x].pop(produtos_de_mercearias[x].index(minimo))
                    cp += 1
                else:
                    break
        except:
            print('Nao')
            break
        if cp == n:
            c += 1
            if c == k:
                print('Sim')
                break
        if cp < n:
            if c == k:
                print('Sim')
                break
            if c < k:
                print('Nao')
                break
