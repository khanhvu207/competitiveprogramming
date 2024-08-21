#include <bits/stdc++.h>

#include <ranges>
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

#ifdef LOCAL
#include "../../debug.h"
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


void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> m(h);
    for (int i = 0; i < h; ++i) {
        cin >> m[i];
    }

    function<bool(int, int)> valid = [&](int x, int y) {
        return not(x < 0 || x >= h || y < 0 || y >= w);
    };

    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    function<bool(int, int)> can_move = [&](int x, int y) {
        if (m[x][y] == '#') return false;
        bool ok = true;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (valid(nx, ny)) {
                ok &= m[nx][ny] != '#';
            }
        }
        return ok;
    };

    vector g(h, vector<vector<pair<int, int>>>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (!can_move(i, j)) continue;
            for (int k = 0; k < 4; ++k) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (valid(nx, ny) && m[nx][ny] == '.') {
                    g[i][j].emplace_back(nx, ny);
                }
            }
        }
    }

    vector vst(h, vector<bool>(w, false));
    int cnt = 0;
    set<pair<int, int>> seen;
    function<void(int, int)> dfs = [&](int x, int y) {
        ++cnt;
        vst[x][y] = true;

        if (!can_move(x, y)) {
            seen.insert({x, y});
            return;
        }

        for (auto [nx, ny] : g[x][y]) {
            if (!vst[nx][ny]) {
                dfs(nx, ny);
            }
            else {
                if (!can_move(nx, ny) && seen.find({nx, ny}) == seen.end()) {
                    ++cnt;
                    seen.insert({nx, ny});
                }
            }
        }
    };

    int res = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (can_move(i, j)) {
                cnt = 0;
                seen.clear();
                dfs(i, j);
                chMax(res, cnt);
            }
        }
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
