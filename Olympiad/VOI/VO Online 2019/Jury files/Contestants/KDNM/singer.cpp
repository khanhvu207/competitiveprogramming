#include <iostream>
#include <stdio.h>

using namespace std;

const int MOD = 998244353;

int inc(int &a, const int &b) {a = (a + b) % MOD;}
int dec(int &a, const int &b) {a = (a - b + MOD) % MOD;}

int n, d, t, f[6425][6425], g1[6425][6425], g2[6425][6425];

int main() {
    freopen("singer.inp", "r", stdin);
    freopen("singer.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> d >> t; --d;
    f[0][0] = g1[0][0] = g2[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= t; ++j) {
            f[i][j] = g1[i - 1][j];
            if (i >= d) {
                dec(f[i][j], g1[i - d][j]);
                if (j) inc(f[i][j], g2[i - d][j - 1]);
            }
            g1[i][j] = (f[i][j] + g1[i - 1][j]) % MOD;
            g2[i][j] = f[i][j]; if (j) inc(g2[i][j], g2[i - 1][j - 1]);
        }
    cout << 2 * f[n][t] % MOD;
}
