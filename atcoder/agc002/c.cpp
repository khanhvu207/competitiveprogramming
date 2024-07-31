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
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int p = -1;
    for (int i = 0; i < n-1; ++i) {
        if (a[i] + a[i+1] >= l) {
            p = i;
            break;
        }
    }

    if (p == -1) {
        cout << "Impossible" << el;
        return;
    }

    cout << "Possible" << el;

    for (int i = 1; i <= p; ++i) {
        cout << i << el;
    }

    for (int j = n-1; j > p; --j) {
        cout << j << el;
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
