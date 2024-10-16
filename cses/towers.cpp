#include <bits/stdc++.h>

#include <ranges>
using namespace std;

#ifdef LOCAL
#include "../debug.h"
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
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> b = a;
    ranges::sort(b);
    int res = 0;
    fenwickDown<int> ft(500005, 0);
    for (int x : a) {
        int y = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
        int l = ft.get(y, 0) + 1;
        chMax(res, l);
        ft.update(y, l);
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
