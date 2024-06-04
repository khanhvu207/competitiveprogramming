#include <bits/stdc++.h>

#include <ranges>
using namespace std;

#ifdef LOCAL
#include "../../debug.h"
#else
#define debug(...) 42
#endif

namespace utils {
template <typename T, typename... Args>
void setValues(const T& value, T& first, Args&... args) {
    first = value;
    if constexpr (sizeof...(args) > 0) {
        setValues(value, args...);
    }
}

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
}
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';
const bool is_multitest = false;

 
void solve() {
    ll h, w, k;
    cin >> h >> w >> k;
    ll x = (k * k - w) % k;
    ll y = (k * k - h) % k;

    ll sh = 0, sw = 0;
    for (ll i = 0; i < h; ++i) {
        ll t;
        cin >> t;
        ll r = (x - t + k) % k;
        sh += r;
    }

    for (ll i = 0; i < w; ++i) {
        ll t;
        cin >> t;
        ll r = (y - t + k) % k;
        sw += r;
    }

    if (abs(sh - sw) % k != 0) {
        cout << -1 << el;
        return;
    }

    ll res = h * w * (k - 1LL) - max(sh, sw);
    cout << res << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
