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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> lo, hi;
    for (int i = 0; 2 * i < n; ++i) {
        if (a[i] * 2 > n) {
            hi.push_back(i);
        }
    }

    for (int i = n / 2; i < n; ++i) {
        if (a[i] * 2 <= n) {
            lo.push_back(i);
        }
    }

    vector<pair<int, int>> res;
    // swap j, k
    function<void(int, int, int)> makeSwap = [&](int i, int j, int k) {
        swap(a[i], a[k]);
        res.emplace_back(i, k);
        swap(a[i], a[j]);
        res.emplace_back(i, j);
        swap(a[i], a[k]);
        res.emplace_back(i, k);  
    };

    ranges::sort(lo);
    // debug(lo);
    for (int i = (int)lo.size() - 1; i >= 0; --i) {
        int j = n - (int)lo.size() + i;
        if (lo[i] == j) continue;
        makeSwap(0, lo[i], j);
    }

    // debug(a);

    ranges::sort(hi);
    for (int i = 0; i < (int)hi.size(); ++i) {
        int j = i;
        if (hi[i] == j) continue;
        makeSwap(n-1, hi[i], j);
    }

    debug(a);

    for (int i = 0, j = n - (int)lo.size(); i < (int)hi.size(); ++i, ++j) {
        swap(a[i], a[j]);
        res.emplace_back(i, j);
    }

    debug(a);
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[a[i]-1] = i;
    }

    for (int i = 0; i < n / 2; ++i) {
        if (pos[i] != i) {
            int j = pos[i];
            pos[a[i]-1] = j;
            pos[i] = i;
            makeSwap(n-1, i, j);
        }
    }

    for (int i = n / 2; i < n; ++i) {
        if (pos[i] != i) {
            int j = pos[i];
            pos[a[i]-1] = j;
            pos[i] = i;
            makeSwap(0, i, j);
        }
    }

    cout << (int)res.size() << el;
    for (auto it : res) {
        auto [x, y] = it;
        cout << x+1 << ' ' << y+1 << el;
    }

    debug(a);
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
