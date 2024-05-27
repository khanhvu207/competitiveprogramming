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
    int n, l, r;
    cin >> n >> l >> r;

    function<int(int, int)> query = [&](int l, int r) {
        cout << "? " << l << ' ' << r << endl;
        int ans;
        cin >> ans;
        if (ans == -1) {
            exit(0);
        }
        return ans;
    };

    int res = 0;
    function<void(int, int)> solve = [&](int i, int j) {
        int tl = (1 << i) * j;
        int tr = (1 << i) * (j + 1) - 1;
        if (tl > r || tr < l) return;
        if (l <= tl && tr <= r) {
            int ans = query(i, j);
            res = (res + ans) % 100;
        }
        else {
            solve(i-1, 0);
            solve(i-1, 1);
        }
    };

    solve(n, 0);
    cout << "! " << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
