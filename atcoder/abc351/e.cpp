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
    int n;
    cin >> n;
    vector<vector<ll>> coordX(2);
    vector<vector<ll>> coordY(2);
    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        ll tx = x - y;
        ll ty = x + y;
        // debug(tx, ty);
        if (abs(tx) % 2 == 0 && abs(ty) % 2 == 0) {
            coordX[0].push_back(tx);
            coordY[0].push_back(ty);
        }
        else {
            coordX[1].push_back(tx);
            coordY[1].push_back(ty);
        }
    }

    ll res = 0;
    for (int z = 0; z < 2; ++z) {
        ranges::sort(coordX[z]);
        ranges::sort(coordY[z]);
        // debug(coordX[z]);
        // debug(coordY[z]);
        ll sumX = accumulate(coordX[z].begin(), coordX[z].end(), 0LL);
        ll sumY = accumulate(coordY[z].begin(), coordY[z].end(), 0LL);
        ll k = (ll)coordX[z].size();
        for (int i = 0; i < (int)coordX[z].size()-1; ++i) {
            --k;

            sumX -= coordX[z][i];
            res += sumX - coordX[z][i] * k;

            sumY -= coordY[z][i];
            res += sumY - coordY[z][i] * k;
        }
    }

    cout << res / 2LL << el;
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
