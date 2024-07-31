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
    string s;
    cin >> s;
    
    int n = (int)s.size();
    const int INF = numeric_limits<int>::max();
    vector<vector<int>> memo(n+1, vector<int>(2, -1));
    function<int(int, bool)> solve = [&](int i, bool carry){
        if (i >= n) {
            return (int)carry;
        }

        int& res = memo[i][carry];
        if (res != -1) return res;
        res = INF;

        int d = s[i] - '0';
        if (carry) {
            chMin(res, 10 - d + solve(i + 1, false));
            chMin(res, 10 - d - 1 + solve(i + 1, true));
        } 
        else {
            chMin(res, d + solve(i + 1, false));
            chMin(res, 1 + 10 - d + solve(i + 1, false));
            chMin(res, 10 - d + solve(i + 1, true));
        }

        return res;
    };

    cout << solve(0, false) << el;
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
