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
const bool is_multitest = false;


void solve() {
    int n;
    cin >> n;
    vector g(n, vector<int>{});
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int x = -1;
    int d = -1;
    function<void(int, int, int)> dfs = [&](int u, int p, int h) {
        if (chMax(d, h)) {
            x = u;
        }
        for (int v : g[u]) {
            if (v != p) {
                dfs(v, u, h+1);
            }
        }
    };
    
    dfs(0, -1, 0);
    d = -1;
    dfs(x, -1, 0);

    vector dp(2, vector<int>(d+1, 0));
    // dp[player][d] = true if they win with the current diameter of d and it is their turn
    dp[0][0] = 1;
    dp[1][0] = 1;
    for (int i = 1; i <= d; ++i) {
        for (int j = 1; j <= 2; ++j) {
            if (i - j >= 0) {
                dp[0][i] |= !dp[1][i-j];
                dp[1][i] |= !dp[0][i-j];
            }
        }
    }

    cout << (dp[0][d] ? "First" : "Second") << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
