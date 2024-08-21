#include <bits/stdc++.h>

#include <ranges>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

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
    ll h, w;
    cin >> h >> w;
    int n;
    cin >> n;

    const int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    const int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    map<array<int, 2>, int> g;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        for (int j = 0; j < 9; ++j) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 1 and nx <= h and ny >= 1 and ny <= w) {
                g[{nx, ny}] += 1;
            }
        }
    }

    vector<ll> res(10, 0);
    for (int k = 1; k <= 9; ++k) {
        for (auto it : g) {
            if (it.second == k) {
                int x = it.first[0];
                int y = it.first[1];
                if (x > 1 and x < h and y > 1 and y < w) {
                    ++res[k];
                }
            }
        }
    }
    res[0] = (h - 2LL) * (w - 2LL) - accumulate(res.begin() + 1, res.end(), 0LL);
    for (ll x : res) {
        cout << x << el;
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
