#include <bits/stdc++.h>

#include <ranges>
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

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

    // pf(i) - pf(j) + a[j] > (i - j + 1) / 2
    // 2pf(i) - i > 2(pf(j) - a[j]) - j + 1
    int n = (int)s.size();
    array<int, 2> res = {-1, -1};
    for (char c = 'a'; c <= 'z'; ++c) {
        int minPf = 1e9;
        int minPfPos = -1;
        int pf = 0;
        for (int i = 0; i < n; ++i) {
            pf += s[i] == c;
            if (minPfPos != -1) {
                if (2 * pf - i > minPf) {
                    res[0] = minPfPos + 1;
                    res[1] = i + 1;
                    break;
                }
            }
            if (chMin(minPf, 2 * (pf - (s[i] == c)) - i + 1)) {
                minPfPos = i;
            }
        }
    }

    cout << res[0] << ' ' << res[1] << el;
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