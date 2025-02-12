#include <bits/stdc++.h>

#include <ranges>
using namespace std;

#ifdef LOCAL
#include "debug.h"
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
    vector dp(4, vector<int>(7, 0));
    for (int i = 1; i <= 6; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j <= 6; ++j) {
            for (int k = j; k <= 6; ++k) {
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    cout << accumulate(dp[3].begin(), dp[3].end(), 0) << el;
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
