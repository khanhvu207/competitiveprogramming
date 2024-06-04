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

namespace ds {
struct data {
    int x;

    data(int new_x) { x = new_x; }

    // Default constructor
    data() { x = 0; }
};

template <typename T>
class lazySegmentTree {
    int sz;
    vector<T> tree;
    vector<T> lazy;

    T combine(const T& a, const T& b) { return max(a, b); }

   public:
    lazySegmentTree(int n) {
        sz = n;
        tree.resize(4 * sz, 0);
        lazy.resize(4 * sz, 0);
    }

    void build(const vector<T>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) >> 1;
            build(arr, v << 1, tl, tm);
            build(arr, v << 1 | 1, tm + 1, tr);
            tree[v] = combine(tree[v << 1], tree[v << 1 | 1]);
        }
    }

    void push(int v) {
        tree[v << 1] += lazy[v];
        lazy[v << 1] += lazy[v];
        tree[v << 1 | 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, T val) {
        if (l > r) return;
        if (tl == l && r == tr) {
            tree[v] += val;
            lazy[v] += val;
        } else {
            push(v);
            int tm = (tl + tr) >> 1;
            update(v << 1, tl, tm, l, min(r, tm), val);
            update(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r, val);
            tree[v] = combine(tree[v << 1], tree[v << 1 | 1]);
        }
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (tl == l && r == tr) {
            return tree[v];
        }
        push(v);
        int tm = (tl + tr) >> 1;
        T leftRet = query(v << 1, tl, tm, l, min(r, tm));
        T rightRet = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(leftRet, rightRet);
    }
};
}  // namespace ds

void solve() {
    int n, d, w;
    cin >> n >> d >> w;
    // w *= 2;
    vector apples(n, pair<int, int>{});
    for (auto& [t, x] : apples) {
        cin >> t >> x;
        // t *= 2;
        x *= 2;
    }
    ranges::sort(apples);
    // debug(apples);

    const int MAXN = 800005;
    ds::lazySegmentTree<int> st(MAXN);
    int res = 0;
    for (int l = 0, r = 0; l < n;) {
        while (r < n && apples[r].first < apples[l].first + d) {
            st.update(1, 0, MAXN - 1, max(apples[r].second - w + 1, 0), min(apples[r].second + w - 1, MAXN - 1), 1);
            ++r;
        }
        chMax(res, st.query(1, 0, MAXN - 1, 0, MAXN - 1));
        // debug(l, r-1, st.query(1, 0, MAXN - 1, 0, MAXN - 1));

        st.update(1, 0, MAXN - 1, max(apples[l].second - w + 1, 0), min(apples[l].second + w - 1, MAXN - 1), -1);
        ++l;
        chMax(r, l);
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
