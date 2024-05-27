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
    int n, t;
    cin >> n >> t;

    vector<int> cntRow(n, 0);
    vector<int> cntCol(n, 0);
    int cntMainDiag = 0;
    int cntOffDiag = 0;

    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        --x;
        int row = x / n;
        int col = x % n;
        cntRow[row]++;
        cntCol[col]++;
        if (col == row) cntMainDiag++;
        if (row + col == n-1) cntOffDiag++;
        if (cntRow[row] == n || cntCol[col] == n || cntMainDiag == n || cntOffDiag == n) {
            cout << i+1 << el;
            return;
        }
    }
    cout << -1 << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
