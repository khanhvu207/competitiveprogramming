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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    vector<bool> vst(n+1, false);
    vector<ld> cache(n+1);
    function<ld(int)> go = [&](int u) {
        ld &res = cache[u];        
        if (vst[u]) {
            return res;
        }
        res = 1.0;
        vst[u] = true;
        if (u == n) {
            return res;
        }

        ld s = (ld)g[u].size();
        ld best = 0.0;
        for (int v : g[u]) {
            chMax(best, go(v));
        }
        res = best / s;
        return res;
    };

    cout << fixed << setprecision(9) << go(1) << el;
}

const bool is_multitest = true;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
