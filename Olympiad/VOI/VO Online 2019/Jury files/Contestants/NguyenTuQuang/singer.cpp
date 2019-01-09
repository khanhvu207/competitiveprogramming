#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 6500;

int n, d, k;
int f[N][N];
int psumf[N][N];
int mem[N << 1];
int solve() {
    if (d == 2) {
        if (k != n - d + 2) return 0;
        int ans = 1;
        for(int i = 1; i <= n; i++) 
            ans = (ans + ans) % MOD;
        return ans;
    }
    f[1][0] = 2;
    psumf[1][0] = 2;

    for(int i = 2; i <= n; i++){
        if (i - d + 1 >= 1)
            for(int j = 0; j <= i - d + 1; j++) {
                int pos = i - d + 1 - j;
                mem[N + pos] = (mem[N + pos] + f[i - d + 1][j]) % MOD;
            }
        for(int j = i; j >= 0; j--) {
            f[i][j] = (psumf[i - 1][j] - psumf[max(0, i - d + 1)][j] + MOD) % MOD;
            f[i][j] = (f[i][j] + mem[N + (i - d - j + 2)]) % MOD; 
            psumf[i][j] = (psumf[i - 1][j] + f[i][j]) % MOD;
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= i; j++) {
            int fin = j + max(0, (n - (i + d - 2) + 1));
            if (fin == k) {
                ans = (ans + f[i][j]) % MOD;
            }
        }
    return ans;
}

int main() {
    freopen("singer.inp", "r", stdin);
    freopen("singer.out", "w", stdout);
    cin >> n >> d >> k;
    cout << solve();
}
