from fractions import gcd

def extended_gcd(aa, bb):
    lastremainder, remainder = abs(aa), abs(bb)
    x, lastx, y, lasty = 0, 1, 1, 0
    while remainder:
        lastremainder, (quotient, remainder) = remainder, divmod(lastremainder, remainder)
        x, lastx = lastx - quotient*x, x
        y, lasty = lasty - quotient*y, y
    return lastremainder, lastx * (-1 if aa < 0 else 1), lasty * (-1 if bb < 0 else 1)
 
def modinv(a, m):
    g, x, _ = extended_gcd(a, m)
    if g != 1:
        raise ValueError
    return x % m

mod = 1000000007
n,m,c = map(int, raw_input().split())
types = pow(c,n*n, mod)

res = 0
for i in range(m):
    res += pow(types, gcd(m,i), mod)

res *= modinv(m, mod)
print(res%mod)