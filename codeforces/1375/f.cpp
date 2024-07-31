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
    vector<ll> a = {0, 0, 0};
    cin >> a[0] >> a[1] >> a[2];
    const ll INF = 10e10;
    cout << "First" << endl;
    cout << INF << endl;
    int p;
    cin >> p;
    if (p == -1) {
        return;
    }
    --p;
    a[p] += INF; 
    ll s = 2LL * a[p];
    for (int i = 0; i < 3; ++i) {
        if (i != p) {
            s -= a[i];
        }
    }
    cout << s << endl;
    int g;
    cin >> g;
    if (g == -1) {
        return;
    }
    --g;
    a[g] += s;
    // debug(a[0], a[1], a[2]);
    cout << a[g] - a[p] << endl;
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
