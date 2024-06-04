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
}
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';
const bool is_multitest = false;

 
void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n+1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int k;
    cin >> k;
    vector<int> c(k);
    for (int &x : c) cin >> x;
    
    const int INF = numeric_limits<int>::max();
    vector d(k, vector<int>(k, 0));
    bool notConnected = false;
    for (int i = 0; i < k; ++i) {
        int st = c[i];
        vector dist(n+1, INF);
        queue<pair<int, int>> q;
        dist[st] = 0;
        q.emplace(0, st);
        while (!q.empty()) {
            auto [du, u] = q.front();
            q.pop();
            for (int v : g[u]) {
                if (chMin(dist[v], dist[u] + 1)) {
                    q.emplace(dist[v], v);
                }
            }
        }
        for (int j = 0; j < k; ++j) {
            d[i][j] = dist[c[j]];
            if (d[i][j] == INF) {
                notConnected = true;
            }
        }
    }

    if (notConnected) {
        cout << -1 << el;
        return;
    }

    const int MAXM = 1 << k;
    vector memo(k, vector<int>(MAXM, -1));
    function<int(int, int)> solve = [&](int last, int mask) {
        int &res = memo[last][mask];
        if (mask == MAXM-1) {
            res = 0;
            return res;
        }

        if (res != -1) return res;

        res = INF;
        for (int i = 0; i < k; ++i) {
            if ((mask >> i) & 1) continue;
            chMin(res, d[last][i] + solve(i, mask | (1 << i)));
        } 
        return res;
    };

    int res = INF;
    for (int i = 0; i < k; ++i) {
        chMin(res, solve(i, 1 << i));
    }
    cout << res + 1 << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
