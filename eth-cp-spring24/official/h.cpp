#include <bits/stdc++.h>
#include <ranges>
using namespace std;

#ifdef LOCAL
#include "debug.h"
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
const bool is_multitest = true;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> timeExpire(m+1);
    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        timeExpire[a[i]].push_back(t[i]);
    }

    int hi = n;
    for (int i = 1; i <= m; ++i) {
        ranges::sort(timeExpire[i]);
        ranges::reverse(timeExpire[i]);
        setMin(hi, (int)timeExpire[i].size());
    }

    function<bool(int)> check = [&](int k) {
        vector<int> times;
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < k; ++j) {
                times.push_back(timeExpire[i][j]);
            }
        }
        ranges::sort(times);
        for (int i = 0; i < (int)times.size(); ++i) {
            if (times[i] < i) return false;
        }
        return true;
    };

    int lo = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << hi << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}