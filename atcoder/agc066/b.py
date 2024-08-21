def sum_digit(x):
    res = 0
    while x:
        res += x % 10
        x //= 10
    return res

def main():
    n = int(input())
    res = 5 ** n
    print(res)

    # Checking
    for i in range(1, n + 1):
        x = res * (2 ** i)
        print(i, x, sum_digit(x))

if __name__ == '__main__':
    main()