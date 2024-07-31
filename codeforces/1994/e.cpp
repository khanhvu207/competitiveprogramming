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

    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < s[i]-1; ++j) {
            int x;
            cin >> x;
        }
    }

    sort(s.rbegin(), s.rend());
    // debug(s);

    int res = s[0];
    for (int i = 1; i < n; ++i) {
        int j = 21;
        vector<int> bits;
        for (; j >= 0; --j) {
            if ((1 << j) & s[i]) {
                bits.push_back(j);
            }
        }

        for (int k : bits) {
            if ((1 << k) & res) {
                res |= (1 << k) - 1;
                break;
            }
            else {
                res |= (1 << k);
            }
        }
    }

    cout << res << el;
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
