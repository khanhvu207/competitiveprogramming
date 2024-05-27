namespace ds {
struct data {
    int x;

    data(int new_x) {
        x = new_x;
    }

    // Default constructor
    data() {
        x = 0;
    }
};

data combine(const data& left, const data& right) {
    // Implement this
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