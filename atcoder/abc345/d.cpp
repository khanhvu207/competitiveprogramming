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


int memo[15][15][1030];

void solve() {
    int n, h, w;
    cin >> n >> h >> w;
    if (h > w) swap(h, w);
    vector<pair<int, int>> tiles;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (x > y) {
            swap(x, y);
        }
        tiles.emplace_back(x, y);
    }

    const int allMask = (1 << n) - 1;
    memset(memo, -1, sizeof memo);
    function<bool(int, int, int)> solve = [&](int cur_h, int cur_w, int mask) {
        if (cur_h > cur_w) {
            swap(cur_h, cur_w);
        }

        int& res = memo[cur_h][cur_w][mask];
        if (res != -1) return (bool) res;
        res = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                auto [x, y] = tiles[i];
                if (x == cur_h && y == cur_w) {
                    res = 1;
                    return (bool)res;
                }
            }
        }

        // Vertical cut
        for (int submask = mask; submask > 0; submask = (submask-1) & mask) {
            for (int i = 1; i < cur_w; ++i) {
                res |= solve(cur_h, i, submask) && solve(cur_h, cur_w-i, mask ^ submask);
            }
        }

        // Horizontal cut
        for (int submask = mask; submask > 0; submask = (submask-1) & mask) {
            for (int i = 1; i < cur_h; ++i) {
                res |= solve(i, cur_w, submask) && solve(cur_h-i, cur_w, mask ^ submask);
            }
        }

        return (bool)res;
    };

    cout << (solve(h, w, allMask) ? "Yes" : "No") << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
