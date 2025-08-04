#include <bits/stdc++.h>

namespace Algebra {
using namespace std;
using ll = long long;
class PrimeSieve {
   public:
    using ll = long long;
    static constexpr int MAXSIEVE = 31622778;

    PrimeSieve() {
        sieve();  // Initialize the sieve in the constructor
    }

    template <typename T>
    T count_divisors(T x) const {
        T res = 1;
        for (int p : prime) {
            if (1LL * p * p > x) break;
            int cnt = 1;
            while (x % p == 0) ++cnt, x /= p;
            res *= cnt;
        }
        if (x > 1) res *= 2;
        return res;
    }

   private:
    bitset<MAXSIEVE> not_composite;
    vector<int> prime;

    void sieve() {
        not_composite.set();  // Initially assume all are primes
        not_composite[0] = not_composite[1] = false;
        for (int i = 2; i * i < MAXSIEVE; ++i) {
            if (not_composite[i]) {
                for (int j = i * i; j < MAXSIEVE; j += i) {
                    not_composite[j] = false;
                }
            }
        }
        for (int i = 2; i < MAXSIEVE; ++i) {
            if (not_composite[i]) prime.emplace_back(i);
        }
    }
};
}  // namespace Algebra