template <typename T>
class fenwickUp {
   public:
    vector<T> a;
    int sz;
    fenwickUp(int n, T init) {
        sz = n;
        a.resize(n, init);
    }

    void update(int idx, T val) {
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            chMax(a[idx], val);
        }
    }

    T get(int idx, T def) {
        T res = def;
        for (; idx < sz; idx = idx | (idx + 1)) {
            chMax(res, a[idx]);
        }
        return res;
    }
};

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