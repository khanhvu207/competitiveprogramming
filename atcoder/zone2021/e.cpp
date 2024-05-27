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
    int r, c;
    cin >> r >> c;
    function<int(int, int)> nodeId = [&](int x, int y) { return x * c + y; };
    function<pair<int, int>(int)> invNodeId = [&](int id) { return make_pair(id / r, id % c); };
    vector a(r, vector<int>(c - 1));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c - 1; ++j) {
            cin >> a[i][j];
        }
    }
    vector b(r - 1, vector<int>(c));
    for (int i = 0; i < r - 1; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> b[i][j];
        }
    }

    vector g(r * c, vector<pair<int, int>>{});
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int u = nodeId(i, j);
            int v;
            if (j + 1 < c) {
                v = nodeId(i, j + 1);
                g[u].emplace_back(v, a[i][j]);
            }
            if (j - 1 >= 0) {
                v = nodeId(i, j - 1);
                g[u].emplace_back(v, a[i][j - 1]);
            }
            if (i + 1 < r) {
                v = nodeId(i + 1, j);
                g[u].emplace_back(v, b[i][j]);
            }

            for (int k = 1; k <= i; ++k) {
                v = nodeId(i - k, j);
                g[u].emplace_back(v, k + 1);
            }
        }
    }

    int n = r * c;
    const int INF = numeric_limits<int>::max();
    function<void(int, vector<int>&, vector<int>&)> dijkstra = [&](int st, vector<int>& d, vector<int>& p) {
        d.assign(n, INF);
        p.assign(n, -1);
        d[st] = 0;
        priority_queue q(greater<>{}, vector<pair<int, int>>{});
        q.emplace(0, st);
        while (!q.empty()) {
            auto [du, u] = q.top();
            q.pop();
            if (du != d[u]) continue;
            for (auto [v, w] : g[u]) {
                if (chMin(d[v], d[u] + w)) {
                    p[v] = u;
                    q.emplace(d[v], v);
                }
            }
        }
    };

    vector<int> dist;
    vector<int> prior;
    int st = nodeId(0, 0);
    int ed = nodeId(r - 1, c - 1);
    dijkstra(st, dist, prior);
    cout << dist[ed] << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
