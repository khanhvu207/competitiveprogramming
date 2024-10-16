#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debug.h"
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
            chMin(a[idx], val);
        }
    }

    T get(int idx, T def) {
        T res = def;
        for (; idx < sz; idx = idx | (idx + 1)) {
            chMin(res, a[idx]);
        }
        return res;
    }
};

template <typename T>
class fenwickUpM {
   public:
    vector<T> a;
    int sz;
    fenwickUpM(int n, T init) {
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

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> h(n);
    for (ll &t : x) cin >> t;
    for (ll &t : h) cin >> t;

    // Compress heights
    vector<ll> h2 = h;
    ranges::sort(h2);
    vector<int> compressedH(n);
    for (int i = 0; i < n; ++i) {
        int j = lower_bound(h2.begin(), h2.end(), h[i]) - h2.begin();
        compressedH[i] = j;
    }

    const ll DEF = numeric_limits<ll>::max();
    vector<ll> res(n, DEF);
    {
        const int INF = 1e9;
        fenwickUp<int> ft(100005, INF);
        for (int i = n-1; i >= 0; --i) {
            int j = ft.get(compressedH[i], INF);
            if (j != INF) {
                // Calculate the isolation radius
                ll heightDiff = h[j] - h[i];
                ll r = (x[j] - heightDiff) - x[i];
                chMin(res[i], r);
            }
            ft.update(compressedH[i], i);
        }
    }

    {
        fenwickUpM<int> ft(100005, -1);
        for (int i = 0; i < n; ++i) {
            int j = ft.get(compressedH[i], -1);
            if (j != -1) {
                // Calculate the isolation radius
                ll heightDiff = h[j] - h[i];
                ll r = x[i] - (x[j] + heightDiff);
                chMin(res[i], r);
            }
            ft.update(compressedH[i], i);
        }
    }    

    for (int i = 0; i < n; ++i) {
        if (res[i] == DEF) cout << 0 << ' ';
        else cout << res[i] << ' ';
    }
    cout << el;
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
