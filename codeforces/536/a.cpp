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
}  // namespace utils
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';


void solve() {
    ll a, b;
    int n;
    cin >> a >> b >> n;
    for (int i = 0; i < n; ++i) {
        ll l, t, m;
        cin >> l >> t >> m;
        ll rlo = l;
        ll rhi = 1e6;
        while (rlo <= rhi) {
            ll rm = (rlo + rhi) >> 1LL;
            ll s = a * (rm - l + 1LL) + b * (rm - l + 1LL) * (l + rm - 2LL) / 2LL;
            ll need = s / m;
            if (s % m) ++need;
            ll rm_val = a + (rm - 1LL) * b;
            if (need <= t && rm_val <= t) {
                rlo = rm + 1LL;
            }
            else {
                rhi = rm - 1LL;
            }
        }

        if (rhi < l) {
            cout << -1 << el;
        }
        else {
            cout << rhi << el;
        }
    }
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
