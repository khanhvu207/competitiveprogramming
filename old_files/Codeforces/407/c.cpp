#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
using namespace std;
 
const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;
int n, m, a[N];
ll fact[N], inv[N], b[105][N];
 
ll nCr(int n, int r) {
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    fact[0] = 1LL;
    inv[N - 1] = 931791584;
    for (int i = 1; i < N; ++i) fact[i] = fact[i - 1] * i * 1LL % MOD;
    for (int i = N - 2; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1LL) * 1LL % MOD;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        b[k][l] += 1LL;
        for (int j = 0; j <= k; ++j) 
            b[j][r + 1] = (b[j][r + 1] - nCr(k - j + r - l, k - j) + MOD) % MOD;
    }
    for (int i = 100; i >= 0; --i) {
        for (int j = 1; j <= n; ++j) {
            (b[i][j] += b[i][j - 1] + b[i + 1][j]) %= MOD;
        }
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = (a[i] + b[0][i]) % MOD;
        cout << a[i] << ' ';
    }
}