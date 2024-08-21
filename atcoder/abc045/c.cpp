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
    string s;
    cin >> s;

    int n = (int)s.size();
    s = '$' + s;
    vector<array<ll, 2>> dp(15);
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        ll cur = 0;
        ll p = 1;
        for (int j = i; j >= 1; --j) {
            cur += p * (s[j] - '0');
            p *= 10;
            dp[i][0] += cur * dp[j-1][1] + dp[j-1][0];
            dp[i][1] += dp[j-1][1];
        }
    }
    cout << dp[n][0] << el;
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
