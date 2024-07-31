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
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;

    // We burn the prefix until T is encountered!
    int pf = 0;
    for (; pf < (int)s.size(); ++pf) {
        if (s[pf] == 'T') break;
        --x;
    }
    s = s.substr(pf, (int)s.size() - pf);
    
    int cnt = 0;
    int t = 0;
    const int MX = 8005;
    vector<vector<int>> a(2);
    for (char c : s) {
        if (c == 'T') {
            if (cnt) {
                a[t].push_back(cnt);
            }
            cnt = 0;
            t ^= 1;
        }
        else {
            ++cnt;
        }
    }
    if (cnt) {
        a[t].push_back(cnt);
    }

    bool res = true;
    vector<vector<bool>> dp(2, vector<bool>(2 * MX, false));
    t = 0;
    dp[t][MX] = true;
    x += MX;
    for (int v : a[0]) {
        for (int i = 0; i < 2 * MX; ++i) {
            dp[t ^ 1][i] = false;
        }
        for (int i = 0; i < 2 * MX; ++i) {
            if (!dp[t][i]) continue;
            if (i - v >= 0) dp[t ^ 1][i - v] = true;
            if (i + v < 2 * MX) dp[t ^ 1][i + v] = true;
        }
        t ^= 1;
    }
    res &= dp[t][x];

    t = 0;
    fill(dp[0].begin(), dp[0].end(), false);
    dp[t][MX] = true;
    y += MX;
    for (int v : a[1]) {
        for (int i = 0; i < 2 * MX; ++i) {
            dp[t ^ 1][i] = false;
        }
        for (int i = 0; i < 2 * MX; ++i) {
            if (!dp[t][i]) continue;
            if (i - v >= 0) dp[t ^ 1][i - v] = true;
            if (i + v < 2 * MX) dp[t ^ 1][i + v] = true;
        }
        t ^= 1;
    }
    res &= dp[t][y]; 

    cout << (res ? "Yes" : "No") << el;
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
