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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n+2, vector<int>(m+2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
        }
    }

    int count = n * m;
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    priority_queue q(greater<>{}, vector<tuple<int, int, int>>{});
    vector<vector<bool>> vst(n+2, vector<bool>(m+2, false));
    for (int i = 1; i <= n; ++i) {
        q.emplace(g[i][1], i, 1);
        if (m > 1) q.emplace(g[i][m], i, m);
        vst[i][1] = true;
        vst[i][m] = true;
    }
    for (int j = 2; j <= m-1; ++j) {
        q.emplace(g[1][j], 1, j);
        if (n > 1) q.emplace(g[n][j], n, j);
        vst[1][j] = true;
        vst[n][j] = true;
    }
    for (int t = 1; t <= k; ++t) {
        while (!q.empty()) {
            auto [h, x, y] = q.top();
            if (h > t) break;
            q.pop();
            // debug(t, h, x, y);
            --count;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
                if (vst[nx][ny]) continue;
                q.emplace(g[nx][ny], nx, ny);
                vst[nx][ny] = true;
            }
        }
        cout << count << el;
    }
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
