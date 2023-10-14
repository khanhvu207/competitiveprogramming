#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x;
    cin >> x;
    ll ans = x, a, b;
    for (ll i = sqrt(x); i >= 1; --i) {
        if (x % i != 0LL) continue;
        if (__gcd(x / i, x / (x / i)) != 1) continue;
        if (max(x / i, x / (x / i)) <= ans) {
            ans = max(x / i, x / (x / i));
            a = x / i, b = x / (x / i);
        }
    }
    if (x == 1) a = 1, b = 1;
    cout << a << ' ' << b << '\n';
}