template <typename T>
class fenwick {
   public:
    vector<T> a;
    int sz;
    const T inf = numeric_limits<T>::max();
    fenwick(int n) {
        sz = n;
        a.resize(n, -inf);
    }

    void update(int idx, T val) {
        for (; idx < sz; idx = idx | (idx + 1)) {
            a[idx] = max(a[idx], val);
        }
    }

    T get(int idx) {
        T res = -inf;
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            res = max(res, a[idx]);
        }
        return res;
    }
};
