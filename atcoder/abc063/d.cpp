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
void setMax(T& target, const T& value) {
    if (value > target) {
        target = value;
    }
}

template <typename T>
void setMin(T& target, const T& value) {
    if (value < target) {
        target = value;
    }
}
}  // namespace utils
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';
const bool is_multitest = false;

void solve() {
    int n;
    cin >> n;
    ll a, b;
    cin >> a >> b;
    vector<ll> h(n);
    for (ll& x : h) cin >> x;

    function valid = [&](ll k) {
        vector<ll> t = h;
        for (ll &x : t) {
            x -= k * b;
        }
        ll d = a - b;
        for (ll x : t) {
            if (x < 0) continue;
            k -= x / d;
            if (x % d) --k;
        }
        return k >= 0;
    };

    ll l = 1, r = 0;
    for (ll x : h) {
        r += x / a;
        if (x & a) ++r;
    }
    while (l <= r) {
        ll m = (l + r) >> 1LL;
        if (valid(m)) {
            r = m - 1LL;
        }
        else {
            l = m + 1LL;
        }
    }
    cout << l << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
