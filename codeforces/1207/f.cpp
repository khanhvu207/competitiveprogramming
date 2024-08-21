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
    const int M = 500000;
    const int C = 300;
    vector<vector<int>> count(C + 5, vector<int>(C + 5, 0));
    int q;
    cin >> q;
    vector<int> a(M+5, 0);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            a[x] += y;
            for (int i = 1; i <= C; ++i) {
                int j = x % i;
                count[i][j] += y;
            }
        }
        else {
            int x, y;
            cin >> x >> y;
            if (x <= C) {
                cout << count[x][y] << el;
            }
            else {
                int res = 0;
                for (int i = y; i <= M; i += x) {
                    res += a[i];
                }
                cout << res << el;
            }
        }
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
