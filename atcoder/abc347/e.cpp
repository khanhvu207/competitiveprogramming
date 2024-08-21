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
    int n, q;
    cin >> n >> q;
    vector<int> x(q);
    for (int &a : x) cin >> a;

    set<int> s;
    vector<ll> pf(q + 1, 0);
    const int MAXN = 2e5 + 5;
    vector<vector<int>> pos(MAXN);
    for (int i = 0; i < q; ++i) {
        if (i > 0) pf[i] = pf[i-1];
        if (s.find(x[i]) == s.end()) {
            ++pf[i];
            s.insert(x[i]);
        }
        else {
            --pf[i];
            s.erase(x[i]);
        }
        pos[x[i]].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        if ((int)pos[i].size() & 1) {
            pos[i].push_back(q);
        }
    }

    for (int i = 1; i <= q; ++i) {
        pf[i] += pf[i-1];
    }
    // debug(pf);

    vector<ll> res(MAXN, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (int)pos[i].size(); j += 2) {
            res[i] += pf[pos[i][j + 1] - 1];
            if (pos[i][j] > 0) res[i] -= pf[pos[i][j] - 1];
        }
        cout << res[i] << ' ';
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
