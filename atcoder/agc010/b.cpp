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
const bool is_multitest = false;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll& x : a) cin >> x;
    ll s = accumulate(a.begin(), a.end(), 0LL);
    ll k = (n + 1LL) * n / 2LL;
    if (s % k) {
        cout << "NO" << el;
        return;
    }

    ll t = s / k;
    bool ok = true;
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        ll d = a[(i + 1) % n] - a[i];
        ll r = t - d;
        if (r < 0 || r % n) {
            ok = false;
            break;
        }
        cnt += r / n;
    }
    ok &= (cnt == t);
    cout << (ok ? "YES" : "NO") << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}