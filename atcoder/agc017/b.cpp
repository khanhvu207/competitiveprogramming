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
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    bool res = false;
    n -= 1LL;
    for (ll k = 0; k <= n; ++k) {
        ll q = n - k;

        ll l = a + k * c - q * d;
        ll r = a + k * d - q * c;
        if (l > r) swap(l, r);
        // debug(k, q, l, r);
        res |= l <= b && b <= r; 

        l = a - k * c + q * d;
        r = a - k * d + q * c;
        if (l > r) swap(l, r);
        // debug(k, q, l, r);
        res |= l <= b && b <= r;
    }

    cout << (res ? "YES" : "NO") << el;
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
