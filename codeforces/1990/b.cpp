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
    int n, x, y;
    cin >> n >> x >> y;
    --x, --y;
    vector<int> a(n, 1);
    int t = -1;
    for (int i = x + 1; i < n; ++i) {
        a[i] = t;
        t = -t;
    }
    t = -1; 
    for (int i = y - 1; i >= 0; --i) {
        a[i] = t;
        t = -t;
    }
    for (int x : a) {
        cout << x << ' ';
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
