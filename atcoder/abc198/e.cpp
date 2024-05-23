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

void solve() {
    int n;
    cin >> n;
    vector<int> color(n);
    for (int &x : color) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    const int MAXC = 100005;
    vector<int> countColor(MAXC, 0);
    vector<int> goodVertices;
    function<void(int, int)> dfs = [&](int u, int p) {
        if (countColor[color[u]] == 0) {
            goodVertices.push_back(u);
        }
        
        ++countColor[color[u]];
        for (int v : g[u]) {
            if (v != p) {
                dfs(v, u);
            }
        }

        --countColor[color[u]];
    };

    dfs(0, -1);
    ranges::sort(goodVertices);
    for (int x : goodVertices) {
        cout << x + 1 << el;
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
