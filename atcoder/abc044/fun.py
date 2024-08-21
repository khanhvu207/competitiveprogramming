for i in range(1000, 2000):
    a = 2 ** i
    b = 5 ** i
    if str(a)[0] == str(b)[0]:
        print(str(a)[0])
        break