#include <bits/stdc++.h>

#include <ranges>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#ifdef LOCAL
#include "../debug.h"
#else
#define debug(...) 42
#endif

namespace utils {
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
    // Define a DP array dp[i][j]
    // dp[i][j] = area of rectangle with bottom-left corner at (i, j) and top-right corner at (0, n-1)
    // Compute the area of rectangle with bottomleft at (i, j) and top-right at (r, t)
    // r = i - k + 1
    // t = j + m - 1
    // Area = dp[i][j] - dp[i][t + 1] - dp[r - 1][]

    int k, n;
    cin >> k >> n;
    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    // Step 1: Compress matrix A into blocks of k rows
    vector<vector<int>> compressedA(n - k + 1, vector<int>(n));

    vector<vector<int>> pfCol(n, vector<int>(n));
    for (int j = 0; j < n; ++j) {
        pfCol[0][j] = A[0][j];
        for (int i = 1; i < n; ++i) {
            pfCol[i][j] = pfCol[i-1][j] + A[i][j];
        }
    }

    for (int i = 0; i < n - k + 1; ++i) {
        int b = i + k - 1;
        for (int j = 0; j < n; ++j) {
            int colVal = pfCol[b][j] - (i > 0 ? pfCol[i - 1][j] : 0);
            compressedA[i][j] = colVal;
        }
    }

    // Step 2: Find the min. subarray in each of the row of compressedA
    int res = numeric_limits<int>::min();
    for (int i = 0; i < n - k + 1; ++i) {
        int minPf = numeric_limits<int>::max();
        
        vector<int> pf(n, 0);
        pf[0] = compressedA[i][0];
        for (int j = 1; j < n; ++j) {
            pf[j] = pf[j-1] + compressedA[i][j];
        }

        for (int j = 0; j < n; ++j) {
            res = max(res, pf[j] - min(0, minPf));
            minPf = min(minPf, pf[j]);
        }
    }

    cout << res << '\n';
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
