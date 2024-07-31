#include <bits/stdc++.h>

// #include <ranges> # Not available until C++20
using namespace std;

#ifdef LOCAL
#include "../../../debug.h"
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

template <typename T>
class fenwick {
   public:
    vector<T> a;
    int sz;
    const T inf = numeric_limits<T>::max();
    fenwick(int n) {
        sz = n;
        a.resize(n, 0);
    }

    void downUpdate(int idx, T val) {
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            a[idx] += val;
        }
    }

    void upUpdate(int idx, T val) {
        for (; idx < sz; idx = idx | (idx + 1)) {
            a[idx] += val;
        }
    }

    T downGet(int idx) {
        T res = 0;
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            res += a[idx];
        }
        return res;
    }

    T upGet(int idx) {
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

    vector<int> ranking;
    vector<int> l(n + 1), r(n + 1), k(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i] >> k[i];
        ranking.emplace_back(l[i]);
        ranking.emplace_back(r[i]);
        ranking.emplace_back(l[i] + k[i] - 1);
        ranking.emplace_back(r[i] - k[i] + 1);
    }

    // ranges::sort(ranking);
    sort(ranking.begin(), ranking.end());
    function<int(int)> remap = [&](int x) { return lower_bound(ranking.begin(), ranking.end(), x) - ranking.begin(); };

    vector<pair<int, int>> q;
    for (int i = 1; i <= n; ++i) {
        q.emplace_back(r[i] - l[i], i);
        q.emplace_back(k[i], -i);
    }
    // ranges::sort(q);
    // ranges::reverse(q);
    sort(q.begin(), q.end());
    reverse(q.begin(), q.end());

    vector<int> res(n + 1, n - 1);
    fenwick<int> treeLeft(1000005);
    fenwick<int> treeRight(1000005);
    int activeIntervals = 0;
    for (auto [len, i] : q) {
        if (i > 0) {
            treeLeft.upUpdate(remap(r[i]), 1);
            treeRight.downUpdate(remap(l[i]), 1);
            ++activeIntervals;
        } else {
            i = -i;
            res[i] = activeIntervals - 1;
            res[i] -= treeLeft.downGet(remap(l[i] + k[i] - 1));
            res[i] -= treeRight.upGet(remap(r[i] - k[i] + 1));
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << res[i] << el;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
