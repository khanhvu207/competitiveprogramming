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


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<ll> f(n, 0);
    vector<ll> h(n, 0);
    vector<ll> sumC(n, 0);
    function<void(int, int)> dfs1 = [&](int u, int p) {
        sumC[u] = c[u];
        if (p != -1) {
            h[u] = h[p] + 1LL;
        }
        for (int v : g[u]) {
            if (v != p) {
                dfs1(v, u);
                sumC[u] += sumC[v];
            }
        }
    };
    dfs1(0, -1);
    for (int i = 1; i < n; ++i) {
        f[0] += c[i] * h[i];
    }

    function<void(int, int, ll)> dfs2 = [&](int u, int p, ll carry) {
        if (u != 0) {
            f[u] = f[p] + sumC[0] - sumC[u] - sumC[u];
        }
        // debug(u, carry);
        for (int v : g[u]) {
            if (v != p) {
                dfs2(v, u, carry);
            }
        }
    };
    dfs2(0, -1, sumC[0]);
    // debug(f);
    ll res = numeric_limits<ll>::max();
    for (int i = 0; i < n; ++i) {
        chMin(res, f[i]);
    }
    cout << res << el;
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
