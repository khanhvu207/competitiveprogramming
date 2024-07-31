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
    ll n;
    cin >> n;
    if (n == 1) {
        cout << 0 << el;
        return;
    }
    --n;

    vector<ll> pow10(19);
    pow10[0] = 1LL;
    for (int i = 1; i < 19; ++i) {
        pow10[i] = pow10[i-1] * 10LL;
    }

    for (int i = 0; i <= 36; ++i) {
        ll d = 9LL * pow10[i / 2];
        if (n > d) {
            n -= d;
            continue;
        }
        else {
            ll b = pow10[i / 2];
            b += n - 1;
            cout << b;
            string s = to_string(b);
            if (i % 2 == 0) {
                s = s.substr(0, (int)s.size() - 1);
            }
            reverse(s.begin(), s.end());
            cout << s;
            return;
        }
    }
    // debug(n);
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
