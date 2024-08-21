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


template <typename T>
class fenwickUp {
   public:
    vector<T> a;
    int sz;
    fenwickUp(int n, T init) {
        sz = n;
        a.resize(n, init);
    }

    void update(int idx, T val) {
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            chMax(a[idx], val);
        }
    }

    T get(int idx, T def) {
        T res = def;
        for (; idx < sz; idx = idx | (idx + 1)) {
            chMax(res, a[idx]);
        }
        return res;
    }
};

template <typename T>
class fenwickDown {
   public:
    vector<T> a;
    int sz;
    fenwickDown(int n, T init) {
        sz = n;
        a.resize(n, init);
    }

    void update(int idx, T val) {
        for (; idx < sz; idx = idx | (idx + 1)) {
            chMax(a[idx], val);
        }
    }

    T get(int idx, T def) {
        T res = def;
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            chMax(res, a[idx]);
        }
        return res;
    }
};

void solve() {
    int n;
    ll c;
    cin >> n >> c;
    int m;
    cin >> m;

    const ll INF = numeric_limits<ll>::max();
    fenwickDown<ll> ftDown(n + 5, -INF);
    fenwickUp<ll> ftUp(n + 5, -INF);
    ftDown.update(0, c);
    ll res = 0;
    for (int i = 0; i < m; ++i) {
        int t;
        ll p;
        cin >> t >> p;
        ll c1 = ftDown.get(t, -INF) - t * c;
        ll c2 = ftUp.get(t, -INF);
        if (c2 != -INF) {
            c2 += t * c;
        }
        ll x = max(c1, c2) + p;
        chMax(res, x); // Why + c?
        ftDown.update(t, x + t * c);
        ftUp.update(t, x - t * c);
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
