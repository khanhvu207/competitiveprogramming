#include <bits/stdc++.h>

#include <ranges>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#ifdef LOCAL
#include "../debug.h"
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
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector<vector<ld>> dp(n, vector<ld>(b + 5, 0));
    for (int i = 1; i <= 6; ++i) {
        dp[0][i] = 1. / 6.;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= b; ++j) {
            for (int k = 1; k <= 6; ++k) {
                if (j >= k) {
                    dp[i][j] += dp[i-1][j - k] * (1. / 6.);
                }
            }
        }
    }

    ld res = 0;
    for (int i = a; i <= b; ++i) {
        res += dp[n-1][i];
    }
    
    cout << fixed << setprecision(6) << round(res * 1000000.0) / 1000000.0 << el;
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
