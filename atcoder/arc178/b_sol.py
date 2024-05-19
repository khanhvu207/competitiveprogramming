MOD = 998244353

# return 10 ^ a
def powten(a):
    return pow(10, a, MOD)

def solve(a1, a2, a3):
    # a1 <= a2
    if a1 > a2:
        a1, a2 = a2, a1
    # impossible
    if a2 != a3 and a2 + 1 != a3:
        return 0
    # a2 == a3
    if a2 != a3:
        return (81 * powten(a1 + a2 - 2) - solve(a1, a2, a2)) % MOD
    # calc
    if a1 == a2:
        return 4 * powten(a1 - 1) * (8 * powten(a1 - 1) + 1) % MOD
    else:
        ans = (9 * powten(a2 - 1) - (11 * powten(a1 - 1) - 1) * pow(2, -1, MOD)) % MOD
        ans = ans * 9 * powten(a1 - 1) % MOD
        return ans
    

# I/O
T = int(input())
for _ in range(T):
    a1, a2, a3 = map(int, input().split())
    print(solve(a1, a2, a3))
