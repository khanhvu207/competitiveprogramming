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

namespace ds {
struct data {
    int x;
    int xOcc;
    int xx;
    int xxOcc;

    data(int new_x, int new_xx, int new_x_occ = 1, int new_xx_occ = 1) {
        x = new_x;
        xx = new_xx;
        xOcc = new_x_occ;
        xxOcc = new_xx_occ;
    }

    // Default constructor
    data() {
        x = 0;
        xx = 0;
        xOcc = 1;
        xxOcc = 1;
    }
};

data combine(const data& left, const data& right) {
    set<int> ranking = {left.x, left.xx, right.x, right.xx};
    vector<pair<int, int>> t = {
        {left.x, left.xOcc},
        {left.xx, left.xxOcc},
        {right.x, right.xOcc},
        {right.xx, right.xxOcc},
    };
    auto it = ranking.end();
    int highest = *(--it);
    int secondHighest = *(--it);

    int highestOcc = 0;
    for (auto [u, c] : t) {
        if (highest == u) {
            highestOcc += c;
        }
    }

    int secondHighestOcc = 0;
    for (auto [u, c] : t) {
        if (secondHighest == u) {
            secondHighestOcc += c;
        }
    }

    return data(highest, secondHighest, highestOcc, secondHighestOcc);
}

template <typename T>
class segmentTree {
    int sz;
    vector<T> tree;

   public:
    segmentTree(int n) {
        sz = n;
        tree.resize(4 * sz);
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

    void update(int v, int tl, int tr, int pos, T val) {
        if (tl == tr) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) >> 1;
            if (pos <= tm) {
                update(v << 1, tl, tm, pos, val);
            } else {
                update(v << 1 | 1, tm + 1, tr, pos, val);
            }
            tree[v] = combine(tree[v << 1], tree[v << 1 | 1]);
        }
    }

    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return T();
        }
        if (tl == l && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) >> 1;
        data leftRet = query(v << 1, tl, tm, l, min(r, tm));
        data rightRet = query(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(leftRet, rightRet);
    }
};
}  // namespace ds


void solve() {
    int n, q;
    cin >> n >> q;
    vector<ds::data> a(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = ds::data(x, 0);
    }

    ds::segmentTree<ds::data> st(n);
    st.build(a, 1, 0, n - 1);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            st.update(1, 0, n - 1, p, ds::data(x, 0));
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            ds::data ret = st.query(1, 0, n - 1, l, r);
            if (ret.xx == 0) {
                cout << 0 << el;
            } else {
                cout << ret.xxOcc << el;
            }
        }
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
