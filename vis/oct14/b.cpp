#include <bits/stdc++.h>
using namespace std;

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

int a[100005];

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

    T combine(const T& x, const T& y) { 
        if (x == -1) return y;
        if (a[x] > a[y]) return x;
        else return y;
    }

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
            return -1;
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
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> lTrail(n, 0);
    vector<int> rTrail(n, 0);
    lTrail[0] = 0;
    int c = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i-1]) {
            ++c;
        }
        else {
            c = 0;
        }
        lTrail[i] = c;
    }

    rTrail[n-1] = 0;
    c = 0;
    for (int i = n-2; i >= 0; --i) {
        if (a[i] >= a[i+1]) {
            ++c;
        }
        else {
            c = 0;
        }
        rTrail[i] = c;
    }

    ds::lazySegmentTree<int> st(100005);
    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 0);
    st.build(indices, 1, 0, n-1);

    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int m = st.query(1, 0, n-1, l, r);
        int lb = m - lTrail[m];
        int rb = m + rTrail[m];
        bool ok = (lb <= l and r <= rb);
        cout << (ok ? "Yes" : "No") << el;
    }
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
