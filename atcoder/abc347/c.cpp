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
    int n, a, b;
    cin >> n;
    cin >> a >> b;
    int m = a + b;
    vector<int> r;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        r.push_back(x % m);
    }

    ranges::sort(r);
    // debug(r);
    bool ok = false;
    ok |= (r[n - 1] - r[0] < a);
    if (n == 2) {
        ok |= (r[0] + m - r[n - 1] < a);
    } 
    for (int i = 0; i < n - 1; ++i) {
        ok |= (r[i] + m - r[i + 1] < a);
    }
    cout << (ok ? "Yes" : "No") << el;
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
