#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long

const int N = 2e5 + 5;
const ll MOD = 1e9 + 7;
int open, close[N];
ll ans, f[N];
std::string s;

ll fpow(ll a, ll p) {
    ll ans = 1LL;
    while (p) {
        if (p & 1LL) ans = ans * a % MOD;
        a = a * a % MOD;
        p >>= 1LL;
    }
    return ans;
}

ll nCr(ll n, ll r) {
    return f[n] * fpow(f[r], MOD - 2LL) % MOD * fpow(f[n - r], MOD - 2LL) % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);  
    std::cin >> s;

    f[0] = 1LL;
    for (int i = 1; i < N; ++i) f[i] = f[i - 1] * i * 1LL % MOD;
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        close[i] = close[i + 1] + (s[i] == ')');
    }
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '(') {
            (ans += nCr(open + close[i + 1], open + 1)) %= MOD;
            ++open;
        }
    }

    std::cout << ans << '\n';
}