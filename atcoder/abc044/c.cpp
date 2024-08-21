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
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    for (int& t : x) cin >> t;
    
    ll res = 0LL;
    // for (int k = 1; k <= n; ++k) {
    //     vector<vector<ll>> dp(2505, vector<ll>(k+5, 0));
    //     dp[0][0] = 1;
    //     for (int t : x) {
    //         for (int i = 2500; i >= 1; --i) {
    //             if (t > i) continue;
    //             for (int j = 1; j <= k; ++j) {
    //                 dp[i][j] += dp[i - t][j - 1];
    //             }
    //         }
    //     }
    //     res += dp[a * k][k];
    // }
    vector<vector<ll>> dp(2505, vector<ll>(55, 0));
    dp[0][0] = 1;
    for (int t : x) {
        for (int i = 2500; i >= 1; --i) {
            if (t > i) continue;
            for (int j = 1; j <= n; ++j) {
                dp[i][j] += dp[i - t][j - 1];
            }
        }
    }
    for (int k = 1; k <= n; ++k) {
        res += dp[a * k][k];
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
