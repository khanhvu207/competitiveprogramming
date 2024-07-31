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
    ll n;
    cin >> n;
    function<bool(ll)> is_square = [] (ll x) {
        ll hx = sqrt(x);
        return hx * hx == x;
    };
    function<bool(ll)> is_valid = [] (ll x) {
        while (x) {
            ll r = x % 10LL;
            if (r == 0) return false;
            x /= 10LL;
        }
        return true;
    };
    function<bool(ll)> is_palin = [] (ll x) {
        string sx = to_string(x);
        string rs = to_string(x);
        reverse(rs.begin(), rs.end());
        return sx == rs;
    };

    for (ll i = 2LL; i * i <= n; ++i) {
        if (n % i == 0LL) {
            if (is_palin(i) && is_valid(i) && is_square(n / i)) {
                
            }
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
