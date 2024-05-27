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
const bool is_multitest = false;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> c;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c.emplace_back(x, 1);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        c.emplace_back(x, 2);
    }
    ranges::sort(c);
    bool check = false;
    for (int i = 0; i < n + m - 1; ++i) {
        check |= c[i].second == c[i+1].second && c[i].second == 1;
    }
    cout << (check ? "Yes" : "No") << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
