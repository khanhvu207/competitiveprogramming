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

    void update(int idx, T val) {
        for (; idx < sz; idx = idx | (idx + 1)) {
            a[idx] += val;
        }
    }

    T get(int idx) {
        T res = 0;
        for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
            res += a[idx];
        }
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector ft(26, fenwick<int>(n + 5));
    for (int i = 0; i < n; ++i) {
        ft[s[i] - 'a'].update(i + 1, 1);
    }

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            char c;
            cin >> x >> c;
            if (s[x - 1] != c) {
                ft[s[x - 1] - 'a'].update(x, -1);
                s[x - 1] = c;
                ft[s[x - 1] - 'a'].update(x, 1);
            }
        } else {
            int l, r;
            cin >> l >> r;
            int res = 0;
            for (int i = 0; i < 26; ++i) {
                int cnt = ft[i].get(r) - ft[i].get(l - 1);
                if (cnt > 0) {
                    ++res;
                }
            }
            cout << res << el;
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
