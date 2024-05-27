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
void setMax(T& target, const T& value) {
    if (value > target) {
        target = value;
    }
}

template <typename T>
void setMin(T& target, const T& value) {
    if (value < target) {
        target = value;
    }
}
}  // namespace utils
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';
const bool is_multitest = false;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    int numVotes = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[0]) {
            ++numVotes;
        }
        else {
            --numVotes;
        }

        if (numVotes == 0) {
            ++res;
        }
        else if (numVotes == 1 && s[i] != s[0]) {
            ++res;
        }
    }

    cout << res + 1 << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
