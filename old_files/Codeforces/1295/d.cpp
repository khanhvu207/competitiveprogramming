#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
#ifdef kvutxdy
    freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    while (q--) {
        ll a, m;
        cin >> a >> m;
        ll g = __gcd(a, m);
        m /= g;
        ll res = 1LL;
        for (ll i = 2; i * i <= m; ++i) {
            if (m % i) continue;
            ll t = 1LL;
            while (m % i == 0) 
                m /= i, t *= i;
            res *= t - (t / i);
        }
        if (m > 1LL) res *= m - 1LL;
        cout << res << '\n';
    }
}