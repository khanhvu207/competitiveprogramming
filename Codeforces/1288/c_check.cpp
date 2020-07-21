#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll MOD = 1e9 + 7;
int n, m;
ll f[11][1005][1005], state;

ll dp(int cur, int preva, int prevb) {
    if (preva > prevb) return 0;
    if (cur >= m) return 1;
    ll& res = f[cur][preva][prevb];
    if (res != -1) return res;
    res = 0;
    // cerr << ++state << '\n';
    // cerr << "hi\n";
    for (int a = preva; a <= n; ++a) {
        for (int b = a; b <= prevb; ++b) {
            (res += dp(cur + 1, a, b)) %= MOD;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    memset(f, -1, sizeof f);
    cout << dp(0, 1, n);
}