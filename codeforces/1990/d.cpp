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
    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    const int INF = 1e9;
    vector<vector<int>> dp(n, vector<int>(4, INF));
    dp[0][0] = a[0] > 0 ? 1 : 0;
    if (a[0] > 0 && a[0] <= 4) {
        if (a[0] <= 2) {
            dp[0][1] = 1;
        }
        else {
            dp[0][3] = 2;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] > 0) {
            chMin(dp[i][0], dp[i-1][0] + 1);
            if (a[i] <= 4) {
                if (a[i] <= 2) {
                    chMin(dp[i][0], dp[i-1][1]);
                    chMin(dp[i][0], dp[i-1][3]);
                    chMin(dp[i][1], dp[i-1][0] + 1);
                    chMin(dp[i][1], dp[i-1][2] + 1);
                }
                else {
                    chMin(dp[i][0], dp[i-1][3]);
                    chMin(dp[i][1], dp[i-1][2] + 1);
                    chMin(dp[i][2], dp[i-1][1] + 1);
                    chMin(dp[i][3], dp[i-1][0] + 2);
                }
            }
        }
        else {
            for (int j = 0; j < 4; ++j) {
                chMin(dp[i][0], dp[i-1][j]);
            }
        }
    }
    cout << dp[n-1][0] << el;
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
