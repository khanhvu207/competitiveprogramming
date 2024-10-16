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

    T combine(const T& a, const T& b) { 
        // return max(a, b); 
        // Implement this
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
            return 0; // Be careful of this null return!
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