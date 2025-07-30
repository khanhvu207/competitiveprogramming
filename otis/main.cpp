#include <bits/stdc++.h>
using namespace std;

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
    // A = 0, B = 1
    int n = 10;
    vector<vector<int>> dp(n+5, vector<int>(n+5, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i - 1 >= 0) {
                dp[i][j] += dp[i-1][j];
            }
            if (j - 1 >= 0) {
                dp[i][j] += dp[i][j-1];
            }
        }
    }

    for (int i = 1; i <= 10; ++i) {
        cout << dp[i][i] << ", ";
    }
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
