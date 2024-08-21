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
    vector<array<int, 2>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i][0] >> p[i][1];
    }

    for (int i = 0; i < n; ++i) {
        int best = -1;
        int best_j = -1;
        for (int j = n - 1; j >= 0; --j) {
            if (i == j) continue;
            int dist = (p[j][0] - p[i][0]) * (p[j][0] - p[i][0]) + (p[j][1] - p[i][1]) * (p[j][1] - p[i][1]);
            if (dist >= best) {
                best = dist;
                best_j = j;
            } 
        }
        cout << best_j + 1 << el;
    }
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
