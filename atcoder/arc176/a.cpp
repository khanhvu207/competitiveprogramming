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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        p.emplace_back(x, y);
    }

    set<pair<int, int>> res;
    int overlapped = 0;
    for (const auto &[x, y] : p) {
        if (res.find({x, y}) != res.end()) {
            ++overlapped;
            continue;
        }
        for (int i = 0; i < n; ++i) {
            int nx = (x + i) % n;
            int ny = (y + i) % n;
            res.emplace(nx, ny);
        }
    }

    for (int i = 0; i < n && 0 < overlapped; ++i) {
        if (res.find({0, i}) != res.end()) continue;
        int x = 0;
        int y = i;
        for (int i = 0; i < n; ++i) {
            int nx = (x + i) % n;
            int ny = (y + i) % n;
            res.emplace(nx, ny);
        }
        --overlapped;
    }

    cout << (int)res.size() << el;
    for (auto [x, y] : res) {
        cout << x+1 << ' ' << y+1 << el;
    }
    cout << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
