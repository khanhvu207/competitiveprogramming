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

template<typename T>
class fenwick {
public:
  vector<T> a;
  int sz;
  const T inf = numeric_limits<T>::max();
  fenwick(int n) {
    sz = n;
    a.resize(n, 0);
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
    vector<int> all;
    vector<pair<int, int>> it;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        all.push_back(l);
        all.push_back(r);
        it.emplace_back(l, r);
    }
    ranges::sort(all);
    ranges::sort(it);
    map<int, int> reindex;
    for (int i = 1; i <= (int)all.size(); ++i) {
        reindex[all[i-1]] = i;
    }

    ll res = 0;
    const int MAXN = 1000005;
    fenwick<ll> ft(MAXN);
    for (auto [x, y] : it) {
        int l = reindex[x];
        int r = reindex[y];
        // debug(l, r);
        res += ft.get(l);
        ft.update(r, 1LL);
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
