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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    const ll even[4] = {2LL, 1LL, 0LL, 1LL};
    const ll odd[4]  = {1LL, 2LL, 1LL, 0LL};

    ll w = c - a;
    ll h = d - b;
    ll res = 4LL * (w / 4LL) * h;
    
    ll t = w % 4LL;
    const ll magic = 17179869184LL;
    
    a = (a + magic) % 4LL;
    ll evenStripe = 0LL;
    ll oddStripe = 0LL;

    for (ll i = 0; i < t; ++i) {
        evenStripe += even[(a + i) % 4LL];
    }

    for (ll i = 0; i < t; ++i) {
        oddStripe += odd[(a + i) % 4LL];
    }

    res += (evenStripe + oddStripe) * (h / 2LL);
    if (h & 1LL) {
        res += (abs(b) & 1LL) ? oddStripe : evenStripe;
    }

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
