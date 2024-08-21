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
    int a, b;
    ll C;
    cin >> a >> b >> C;
    int c = __builtin_popcountll(C);
    if (a + b >= c) {
        for (int i = 0; i <= c; ++i) {
            if (a >= i && b >= c - i) {
                int ra = a - i;
                int rb = b - c + i;
                // debug(i, ra, rb);
                if (ra == rb) {
                    ll ansa = 0;
                    ll ansb = 0;
                    int k = i;
                    for (ll j = 0; j < 60; ++j) {
                        if (C & (1LL << j)) {
                            if (k > 0) ansa += (1LL << j), --k;
                            else ansb += (1LL << j);
                        }
                        else {
                            if (ra > 0) {
                                ansa += (1LL << j);
                                ansb += (1LL << j);
                                --ra;
                            }
                        }
                    }
                    if (ra == 0) {
                        cout << ansa << ' ' << ansb << el;
                        return;
                    }
                }
            }
        }
    }
    cout << -1 << el;
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
