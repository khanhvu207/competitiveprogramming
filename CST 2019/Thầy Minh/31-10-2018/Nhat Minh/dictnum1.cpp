#include <iostream>
#include <stdio.h>

using namespace std;

int n, k;
long long dp[115][115];

void trace(long long t, int i, int n) {
    if (n == 0) {cout << '\n'; return;}
    for (int x = k; x >= 0; --x)
        if (x * i <= n) {
            if (dp[i + 1][n - x * i] >= t) {
                for (int xx = 1; xx <= x; ++xx)
                    cout << i << ' ';
                trace(t, i + 1, n - x * i); return;
            }
            else t -= dp[i + 1][n - x * i];
        }
}

int main() {
    freopen("dictnum1.inp", "r", stdin);
    freopen("dictnum1.out", "w", stdout);
    cin >> n >> k;
    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; --i)
        for (int j = 0; j <= n; ++j)
            for (int x = 0; x <= k; ++x)
                if (x * i <= j)
                    dp[i][j] += dp[i + 1][j - x * i];
    for (long long t; cin >> t;)
        trace(t, 1, n);
}
