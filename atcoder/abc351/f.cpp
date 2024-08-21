#include <bits/stdc++.h>

#include <ranges>
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

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

template <typename T>
class fenwick {
   public:
    vector<T> a;
    int sz;
    const T inf = numeric_limits<T>::max();
    fenwick(int n, T init) {
        sz = n;
        a.resize(n, init);
    }

    void update(int idx, T val) {
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            a[idx] += val;
        }
    }

    T get(int idx) {
        T res = 0;
        for (; idx < sz; idx = idx | (idx + 1)) {
            res += a[idx];
        }
        return res;
    }
};


void solve() {
    int n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    ranges::sort(a);
    ranges::reverse(a);
    
    ll res = 0;
    fenwick<ll> ft_val(n+5, 0);
    fenwick<ll> ft_cnt(n+5, 0);
    for (auto [val, pos] : a) {
        ll upVal = ft_val.get(pos + 1);
        ll upCnt = ft_cnt.get(pos + 1);
        res += upVal - upCnt * val;
        ft_val.update(pos, val);
        ft_cnt.update(pos, 1);
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
