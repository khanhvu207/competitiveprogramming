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
const bool is_multitest = true;

ll fpow(ll a, ll p, ll MOD) {
    ll ret = 1LL;
    while (p) {
        if (p & 1LL) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        p >>= 1LL;
    }
    return ret;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    
    if (n >= m) {
        ll p = max(n - k - 1LL, 0LL) / (m - k);
        n -= p * (m - k);
        if (n == m) n = k;
    }
    
    if (n == m-1LL && k == m-1LL) {
        cout << 0 << el;
        return;
    }

    cout << fpow(2LL, n, 10LL) << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
