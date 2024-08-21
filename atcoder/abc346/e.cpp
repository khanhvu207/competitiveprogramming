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
    ll h, w;
    int m;
    cin >> h >> w >> m;
    const int MAXC = 2e5 + 5;
    vector<ll> count(MAXC, 0);
    vector<tuple<int, int, int>> updates;
    for (int i = 0; i < m; ++i) {
        int t, a, x;
        cin >> t >> a >> x;
        updates.emplace_back(t, a, x);
    }

    ll freeH = h;
    ll freeW = w;
    vector<bool> vstH(h+1, false);
    vector<bool> vstW(w+1, false);
    ranges::reverse(updates);
    for (auto &[t, a, x] : updates) {
        if (t == 1) {
            if (!vstH[a]) {
                count[x] += freeW;
                vstH[a] = true;
                --freeH;
            }
        }
        else {
            if (!vstW[a]) {
                count[x] += freeH;
                vstW[a] = true;
                --freeW;
            }
        }
    }

    count[0] += freeH * freeW;
    vector<pair<int, ll>> res;
    for (int i = 0; i < MAXC; ++i) {
        if (count[i] != 0) {
            res.emplace_back(i, count[i]);
        }
    }
    
    cout << (int)res.size() << el;
    for (auto& [i, x] : res) {
        cout << i << ' ' << x << el;
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
