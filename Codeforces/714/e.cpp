// A very classical problem with gorgeous observations leading to a simple DP solution.
// An alternative is using slope trick, which probably I would investigate later.

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const ll inf = 1e18;
const int N = 3005;
ll n, a[N], b[N], dp[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] -= i;
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    dp[1][0] = inf;
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = min(abs(b[i] - a[1]), dp[1][i - 1]);
    }
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = inf;
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j] + abs(b[j] - a[i]));
        }
    }
    cout << dp[n][n];
}