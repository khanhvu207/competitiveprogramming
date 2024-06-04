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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    ll s = accumulate(a.begin(), a.end(), 0LL);


    function check = [&](ll q) {
        vector<ll> b;
        ll sub = 0;
        for (ll t : a) {
            if (t % q != 0) {
                b.push_back(t % q);
                sub += t % q;
            }
        }
        ranges::sort(b);
        ll add = 0;
        for (int i = (int)b.size()-1; i >= 1; --i) {
            add += q - b[i];
            sub -= b[i];
            if (max(add, sub) <= k) {
                return true;
            }
        }
        return false;
    };

    ll res = 1;
    for (ll i = 1; i * i <= s; ++i) {
        if (s % i == 0) {
            if (check(i)) {
                chMax(res, i);
            }
            if (check(s / i)) {
                chMax(res, s / i);
            }
        }
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
