#include <bits/stdc++.h>

#include <ranges>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#ifdef LOCAL
#include "../../debug.h"
#else
#define debug(...) 42
#endif

namespace utils {
template <typename T>
bool chMax(T& target, const T& value) {
    if (value > target) {
        target = value;
        return true;
    }
    return false;
}

template <typename T>
bool chMin(T& target, const T& value) {
    if (value < target) {
        target = value;
        return true;
    }
    return false;
}
}  // namespace utils
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';


void solve() {
    ll n, s;
    cin >> n >> s;

    for (ll b = 2; b * b <= n; ++b) {
        ll curS = 0;
        ll t = n;
        while (t > 0) {
            curS += t % b;
            t /= b;
        }
        if (curS == s) {
            cout << b << el;
            return;
        }
    }

    // debug("hi");
    const ll INF = numeric_limits<ll>::max();
    ll res = INF;
    if (s == n) {
        res = n + 1;
    }
    for (ll q = 1; q * q <= n && q <= s; ++q) {
        ll r = s - q;
        if (n >= r and (n - r) % q == 0) {
            ll b = (n - r) / q;
            if (b >= 2 and b > q and b > r and (q * b + r == n)) {
                chMin(res, b);
            }
        }
    }
    if (res == INF) res = -1;
    cout << res << el;
}

const bool is_multitest = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
