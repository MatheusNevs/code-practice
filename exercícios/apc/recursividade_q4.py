def JaChegou(n, s):
    if n != 0:
        print(s)
    else:
        return
    JaChegou(n-1, s)

JaChegou(2, 'APC eh melhor que ISC?')