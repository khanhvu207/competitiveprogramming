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
    int n;
    cin >> n;
    vector<ll> a(n);

    for (auto &x : a) cin >> x;
    ranges::sort(a);

    const ll MOD = 100000000;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        ll x = a[i];
        ll y = MOD - x;
        int j = lower_bound(a.begin() + i, a.end(), y) - a.begin();
        // debug(x, j);
        if (j == i) ++j;
        res -= MOD * (n - j);
        res += 1LL * i * x;
        res += (n - i - 1LL) * x;
    }
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
