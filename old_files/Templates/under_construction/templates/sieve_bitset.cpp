#include <bits/stdc++.h>
using namespace std;

const int MAXSIEVE = 2E7 + 5;
bitset <MAXSIEVE> notComposite;
vector <int> prime;

/**
 * Prime factorization
 * Time complexity: O(log(n))
 */ 
long long countDivisors(int x) {
    long long res = 1LL;
    for (int p : prime) {
        if (p * p > x) break;
        long long cnt = 1LL;
        while (x % p == 0) ++cnt, x /= p;
        res *= cnt;
    }
    if (x > 1) res *= 2LL;
    return res;
}

/**
 * Sieve of Eratosthenes (bitset)
 * Time complexity: O(n * log(log(n)) / 8) <-- x8 times faster
 * Memory complexity: O(MAXSIEVE)
 * 
 * notComposite.test(i) = true if i is prime
 * vector<int> prime stores prime numbers upto MAXSIEVE
 * 
 * Execution time on:
 *      Codeforces: ~108ms
 */
void sieve() {
    notComposite.flip();
    for (int i = 2; i * i < MAXSIEVE; ++i)
        if (notComposite.test(i))
            for (int j = i * i; j < MAXSIEVE; j += i) notComposite.reset(j);
    for (int i = 2; i < MAXSIEVE; ++i)
        if (notComposite.test(i)) prime.emplace_back(i);
}

int main() {
    sieve();
    return 0;
}