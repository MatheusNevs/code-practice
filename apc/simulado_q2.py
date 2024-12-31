while True:
    try:
        times = [x for x in input().split()]
        times  = [x.split(':') for x in times]
        pa, cb, pb, ca = [int(x[0])*60 + int(x[1]) for x in times]
        t1 = cb - pa
        t2 = ca - pb
        f = (t1 - t2)/2
        v = t1 - f
        if v < 0:
            t1 = (cb + 12*60) - (pa)
            t2 = (ca + 12*60) - (pb)
            f = (t1 - t2)/2
            v = t1 - f
        # if t1 < t2:
        #     f = (t2 - t1)/2
        #     v = abs(f - t2)
        print(int(v), int(f/60))
    except EOFError:
        break
