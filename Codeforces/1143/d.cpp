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
    ll n, k, a, b, x, y;
    cin >> n >> k >> a >> b;
    x = numeric_limits<ll>::max();
    y = -x;
    for (ll i = 0LL; i <= n * k; i += k) {
        ll jump = i + a + b;
        if (jump <= n * k) {
            x = min(x, n * k / __gcd(n * k, jump));
            y = max(y, n * k / __gcd(n * k, jump));
        }
        jump = i + abs(a - b);
        if (jump == 0) jump = k;
        if (jump <= n * k) {
            x = min(x, n * k / __gcd(n * k, jump));
            y = max(y, n * k / __gcd(n * k, jump));
        }
        jump = i - a - b;
        if (jump > 0) {
            x = min(x, n * k / __gcd(n * k, jump));
            y = max(y, n * k / __gcd(n * k, jump));
        }
    }
    cout << x << ' ' << y << '\n';
}