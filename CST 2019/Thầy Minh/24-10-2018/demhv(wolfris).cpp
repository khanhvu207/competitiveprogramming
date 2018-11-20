#include <stdio.h>
#include <string.h>

using namespace std;

const int MOD = 1e9 + 7;

int n, k; long long factorial[100015], dp[20][20], res;

long long power(long long a, int b) {
    if (b == 1) return a;
    long long res = power(a, b >> 1);
    res = res * res % MOD;
    if (b & 1) res = res * a % MOD;
    return res;
}

long long P(int n, int k) {
    if (n < k) return 0;
    return factorial[n] * power(factorial[n - k], MOD - 2) % MOD;
}

int main() {
    //freopen("demhv.inp", "r", stdin);
    //freopen("demhv.out", "w", stdout);
    factorial[0] = 1;
    for (int i = 1; i <= 1e5; ++i)
        factorial[i] = factorial[i - 1] * i % MOD;
    while (scanf("%d %d", &n, &k) == 2) {
        memset(dp, -1, sizeof dp);
        res = 0;
        for (int i = 0; i < n; ++i) {
            int lower = 0, higher = 0;
            for (int l = 0, r = n - 1; l <= r;) {
                int m = (l + r + 1) / 2;
                if (m < i)
                    ++lower, l = m + 1;
                else if (m > i)
                    ++higher, r = m - 1;
                else break;
            }
            if (dp[lower][higher] == -1)
                dp[lower][higher] = factorial[n - 1 - lower - higher] * (P(k - 1, lower) * P(n - k, higher) % MOD) % MOD;
            res = (res + dp[lower][higher]) % MOD;
        }
        printf("%lld\n", res);
    }
}
