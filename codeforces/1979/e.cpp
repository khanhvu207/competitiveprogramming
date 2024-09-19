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
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> op;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        op.emplace_back(x + y, x - y);
    }

    for (int _ = 0; _ < 2; _++) {
        vector<pair<pair<int, int>, int>> p;
        unordered_map<int, vector<pair<int, int>>> a;

        for (int i = 0; i < n; ++i) {
            auto [x, y] = op[i];
            p.emplace_back(make_pair(x, y), i);
            a[x].emplace_back(y, i);
        }

        ranges::sort(p);
        for (auto& [_, vec] : a) {
            ranges::sort(vec);
        }

        for (int i = 0; i < n; ++i) {
            auto [xi, yi] = p[i].first;
            if (a[xi].size() < 2) continue;

            int yj = yi + d;
            auto ij = ranges::lower_bound(a[xi], make_pair(yj, 0));
            if (ij == a[xi].end() || ij->first != yj) continue;

            for (int dx : {d, -d}) {
                int xk = xi + dx;
                if (a.contains(xk)) {
                    auto ik = ranges::lower_bound(a[xk], make_pair(yi, 0));
                    if (ik != a[xk].end() && yi <= ik->first && ik->first <= yj) {
                        cout << p[i].second + 1 << ' ' << ij->second + 1 << ' ' << ik->second + 1 << '\n';
                        return;
                    }
                }
            }
        }

        for (auto& [x, y] : op) {
            swap(x, y);
        }
    }

    cout << "0 0 0\n";
}

const bool is_multitest = true;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
