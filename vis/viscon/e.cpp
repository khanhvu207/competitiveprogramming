#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../debug.h"
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
    int z, n, m;
    cin >> z >> n >> m;
    vector scoreS(n, vector<ll>(26, -1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < z; ++j) {
            cin >> scoreS[i][j];
        }
    }
    vector scoreT(m, vector<ll>(26, -1));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < z; ++j) {
            cin >> scoreT[i][j];
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
