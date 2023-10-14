#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

int n, k, m, a[115];
long long dp[115][115];

int main() {
    freopen("dictnum2.inp", "r", stdin);
    freopen("dictnum2.out", "w", stdout);
    cin >> n >> k;
    dp[n + 1][0] = 1;
    for (int i = n; i >= 1; --i)
        for (int j = 0; j <= n; ++j)
            for (int x = 0; x <= k; ++x)
                if (x * i <= j)
                    dp[i][j] += dp[i + 1][j - x * i];
    string s; getline(cin, s);
    while (getline(cin, s)) {
        stringstream ss(s);
        m = 0; while (ss >> a[++m]);
        long long t = 1;
        for (int i = 1, j = n, l = 1; j; ++i) {
            int x; for (x = 0; l + x < m && a[l + x] == i; ++x); l += x;
            for (int xx = k; xx > x; --xx)
                if (j >= xx * i) t += dp[i + 1][j - xx * i];
            j -= x * i;
        }
        cout << t << '\n';
    }
}
