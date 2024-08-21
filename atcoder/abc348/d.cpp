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
    int h, w;
    cin >> h >> w;
    int s, t;
    vector<vector<char>> m(h, vector<char>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> m[i][j];
            if (m[i][j] == 'S') {
                s = j + w * i;
            }
            else if (m[i][j] == 'T') {
                t = j + w * i;
            }
        }
    }

    int n;
    cin >> n;
    vector<vector<int>> g(h * w);
    vector<vector<int>> a(h, vector<int>(w, 0));
    vector<array<int, 2>> med(n);
    for (int i = 0; i < n; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        --x, --y;
        a[x][y] = c;
        med[i] = {x, y};
    }

    const int INF = numeric_limits<int>::max();
    for (auto [x, y] : med) {
        int at = y + x * w;
        queue<pair<int, int>> q;
        vector<int> dist(h * w, INF);
        q.emplace(x, y);
        dist[y + x * w] = 0;
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, -1, 0, 1};

        while (!q.empty()) {
            auto [sx, sy] = q.front();
            q.pop();

            if (sx != x || sy != y) {
                int to = sy + sx * w;
                if (a[sx][sy] > 0 || m[sx][sy] == 'T') {
                    // debug(x, y, sx, sy);
                    g[at].push_back(to);
                }
            }

            for (int i = 0; i < 4; ++i) {
                int tx = sx + dx[i];
                int ty = sy + dy[i];
                if (tx < 0 || tx >= h || ty < 0 || ty >= w) continue;
                if (m[tx][ty] == '#') continue;
                if (dist[ty + tx * w] > dist[sy + sx * w] + 1) {
                    q.emplace(tx, ty);
                    dist[ty + tx * w] = dist[sy + sx * w] + 1; 
                }
                 
            }
        } 
    }

    vector<bool> vst(h * w, false);
    function<void(int)> dfs = [&](int u) {
        vst[u] = true;
        for (int v : g[u]) {
            if (!vst[v]) {
                dfs(v);
            }
        }
    };

    dfs(s);
    cout << (vst[t] ? "Yes" : "No") << el;
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
