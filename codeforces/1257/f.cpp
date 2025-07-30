#include <bits/stdc++.h>

#include <ranges>
using namespace std;

#ifdef LOCAL
#include "../../debug.h"
#else
#define debug(...) 42
#endif

namespace utils {
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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    vector<int> T(n);
    for (int i = 0; i < n; ++i) {
        T[i] = __builtin_popcount(a[i]);
    }

    const int MAXB = 30;
    vector<vector<int>> V(MAXB, vector<int>(n));
    for (int i = 0; i < MAXB; ++i) {
        for (int j = 0; j < n; ++j) {
            V[i][j] = (a[j] & (1 << i)) ? -1 : 1;
        }
    }

    set<pair<vector<int>, int>> fi, se;
    for (int mask = 0; mask < (1 << 15); ++mask) {
        vector<int> C(n, 0);
        for (int i = 0; i < 15; ++i) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; ++j) {
                    C[j] += V[i][j];
                }
            }
        }
        fi.emplace(C, mask);
    }

    for (int mask = 0; mask < (1 << 15); ++mask) {
        vector<int> C(n, 0);
        for (int i = 0; i < 15; ++i) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; ++j) {
                    C[j] += V[15 + i][j];
                }
            }
        }
        se.emplace(C, mask << 15);
    }

    for (int b = 0; b <= 30; ++b) {
        vector<int> G(n);
        for (int i = 0; i < n; ++i) {
            G[i] = b - T[i];
        }
        for (const auto &item : fi) {
            vector<int> f = item.first;
            int x1 = item.second;
            vector<int> q = G;
            for (int i = 0; i < n; ++i) {
                q[i] -= f[i];
            }
            auto res = se.lower_bound({q, 0});
            if (res == se.end()) continue;
            vector<int> s = (*res).first;
            int x2 = (*res).second;
            if (s == q) {
                // debug(b, f, s);
                cout << x1 + x2 << el;
                return;
            } 
        }
    }
    cout << -1 << el;
    return;
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
