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
    ll l;
    cin >> n >> l;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    for (const ll &x : a) {
        if ((x & 1) && (l & 1)) {
            cout << -1 << el;
            continue;
        }

        // x <= b * (l / 2) * (l - l / 2)
        ll div = (l / 2LL) * (l - l / 2LL);
        ll b = (x + div - 1LL) / div;
        ll hi = b * div;
        ll lo = b * (l - 1LL);
        // debug(x, b, lo, hi);
        if (lo > x) {
            cout << -1 << el;
        }
        else {
            cout << b << el;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
