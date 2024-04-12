const int MAXSIEVE = 31622778;
bitset<MAXSIEVE> not_composite;
vector<int> prime;

ll count_divisors(ll x) {
    int res = 1LL;
    for (int p: prime) {
        if (p * p * 1LL > x) break;
        int cnt = 1LL;
        while (x % p == 0) ++cnt, x /= p;
        res *= cnt;
    }
    if (x > 1) res *= 2LL;
    return res;
}

void sieve() {
    not_composite.flip();
    for (int i = 2; i * i < MAXSIEVE; ++i)
        if (not_composite.test(i))
            for (int j = i * i; j < MAXSIEVE; j += i) 
                not_composite.reset(j);
    for (int i = 2; i < MAXSIEVE; ++i)
        if (not_composite.test(i)) 
            prime.emplace_back(i);
}
