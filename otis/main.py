import sympy

primes = list(sympy.primerange(1, 10**5))

count_pairs = 0
for p in primes:
    for q in primes:
        if q ** 3 > 10 ** 10: break
        N = p ** 2 + q ** 3
        if N < 10 ** 10:
            # Check if every number from 0 and 9 appears exactly once in N
            if sorted(str(N)) == list('0123456789'):
                count_pairs += 1

print(count_pairs)