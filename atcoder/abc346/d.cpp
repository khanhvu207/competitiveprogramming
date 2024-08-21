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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> c(n);
    for (ll &x : c) cin >> x;

    vector<ll> zPf(n), oPf(n), zSf(n), oSf(n);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            zPf[i] = (s[i] != '0') * c[i];
            oPf[i] = (s[i] != '1') * c[i];
        }
        else {
            zPf[i] = (s[i] != '1') * c[i];
            oPf[i] = (s[i] != '0') * c[i];
        }
        if (i > 0) {
            zPf[i] += zPf[i-1];
            oPf[i] += oPf[i-1];
        }
    }

    // debug(zPf, oPf);

    for (int j = 0; j < n; ++j) {
        int i = n - 1 - j;
        if (j % 2 == 0) {
            zSf[i] = (s[i] != '0') * c[i];
            oSf[i] = (s[i] != '1') * c[i];
        }
        else {
            zSf[i] = (s[i] != '1') * c[i];
            oSf[i] = (s[i] != '0') * c[i];
        }
        if (i < n-1) {
            zSf[i] += zSf[i+1];
            oSf[i] += oSf[i+1];
        }
    }

    // debug(zSf);
    // debug(oSf);

    ll res = numeric_limits<ll>::max();
    for (int i = 0; i < n-1; ++i) {
        int j = n - 1 - i;
        ll cost = 0;
        // Zero
        if (i % 2 == 0) {
            cost += zPf[i];
        }
        else {
            cost += oPf[i];
        }
        if (j % 2 == 0) {
            cost += oSf[i+1];
        }
        else {
            cost += zSf[i+1];
        }
        chMin(res, cost);
        // debug(i, cost);
        // debug(i, cost);

        // One
        cost = 0;
        if (i % 2 == 0) {
            cost += oPf[i];
        }
        else {
            cost += zPf[i];
        }
        if (j % 2 == 0) {
            cost += zSf[i+1];
        }
        else {
            cost += oSf[i+1];
        } 
        chMin(res, cost);
    }

    cout << res << el;
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
