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
const bool is_multitest = false;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        ll res = 0;
        ll x = 0, y = 0, z = 0;
        ll xy = 0, yz = 0;
        for (int a = 0, c = -1; c < n; ++a) {
            if (a > 0) {
                if (s[a-1] == 'D') {
                    --x;
                    xy -= y;
                }
                else if (s[a-1] == 'M') {
                    --y;
                    yz -= z;
                }
                else if (s[a-1] == 'C') {
                    --z;
                }
            }

            while (c + 1 < n && c + 1 < a + k) {
                ++c;
                if (s[c] == 'D') {
                    ++x;
                }
                else if (s[c] == 'M') {
                    ++y;
                    xy += x;
                }
                else if (s[c] == 'C') {
                    ++z;
                    yz += y;
                    res += xy;
                }
            }

            if (c == n-1) break;
            // debug(a, c, xy, yz, res);
            // cerr << s[c] << '\n';
        }
        cout << res << el;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
