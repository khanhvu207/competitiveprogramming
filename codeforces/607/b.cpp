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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector dp(n, vector<int>(n, n));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        if (i + 1 < n) {
            dp[i][i+1] = (a[i] == a[i+1] ? 1 : 2);
        }
    }
    for (int i = 2; i < n; ++i) {
        for (int j = i - 2; j >= 0; --j) {
            dp[j][i] = i - j + 1;

            if (a[j] == a[i]) {
                chMin(dp[j][i], dp[j+1][i-1]);
            }

            for (int k = j; k < i; ++k) {
                chMin(dp[j][i], dp[j][k] + dp[k+1][i]);
            }
        }
    }
    cout << dp[0][n-1] << el;
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
