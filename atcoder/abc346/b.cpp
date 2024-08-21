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
    string s = "wbwbwwbwbwbw";
    for (int i = 0; i < 5; ++i) {
        s = s + s;
    }
    int w, b;
    cin >> w >> b;
    int n = w + b;
    bool res = false;
    for (int i = 0; i + n < (int)s.length(); ++i) {
        int countW = 0;
        int countB = 0;
        for (int j = i; j < i + n; ++j) {
            if (s[j] == 'w') ++countW;
            else ++countB;
        }
        res |= (w == countW) && (b == countB);
    }
    cout << (res ? "Yes" : "No") << el;
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
