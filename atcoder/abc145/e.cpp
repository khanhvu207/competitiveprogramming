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
    int t;
    cin >> t;

    vector<pair<int, int>> items;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        items.emplace_back(a, b);
    }

    sort(items.begin(), items.end());

    const int MAXD = 7000;
    const int INF = numeric_limits<int>::max();
    vector<int> dp(MAXD, -INF);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = t-1; j >= 0; --j) {
            if (dp[j] != -INF) {
                int a = items[i].first;
                int b = items[i].second;
                chMax(dp[j + a], dp[j] + b);
            }
        }
    }

    int res = *max_element(dp.begin(), dp.end());
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
