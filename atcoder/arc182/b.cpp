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
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            cout << 1 << ' ';
        }
        cout << el;
        return;
    }

    for (int i = (1 << (k - 2)); i < (1 << (k - 1)) && n > 0; ++i, --n) {
        cout << (i << 1) + 1 << ' ';
    }

    for (int i = (1 << (k - 2)); i < (1 << (k - 1)) && n > 0; ++i, --n) {
        cout << (i << 1) << ' ';
    }

    for (int i = 0; i < n; ++i) {
        cout << 1 << ' ';
    }
    cout << el;
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
