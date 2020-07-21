#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
int n, m;
ll dp[15][1005], f[15][1005];

ll dpUp(int cur, int prev) {
    if (cur >= m) return 1;
    ll& res = dp[cur][prev];
    if (res != -1) return res;
    res = 0LL;
    for (int i = prev; i <= n; ++i) {
        (res += dpUp(cur + 1, i)) %= MOD;
    }
    return res;
}

ll dpDown(int cur, int prev) {
    if (cur >= m) return 1;
    ll& res = f[cur][prev];
    if (res != -1) return res;
    res = 0LL;
    for (int i = prev; i >= 1; --i) {
        (res += dpDown(cur + 1, i)) %= MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    memset(f, -1, sizeof f);
    dpUp(0, 1);
    dpDown(0, n);
    ll res = 0LL;
    for (int i = 1; i <= n; ++i) {
        ll sum = 0LL;
        for (int j = 1; j <= i; ++j) 
            (sum += dpDown(1, j)) %= MOD;
        (res += dpUp(1, i) % MOD * sum % MOD) %= MOD;
    }
    cout << res;
}