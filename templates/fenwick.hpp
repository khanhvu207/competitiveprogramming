template <typename T>
class fenwick {
   public:
    vector<T> a;
    int sz;
    fenwick(int n, T init) {
        sz = n;
        a.resize(n, init);
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

template <typename T>
class fenwick {
   public:
    vector<T> a;
    int sz;
    fenwick(int n, T init) {
        sz = n;
        a.resize(n, init);
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