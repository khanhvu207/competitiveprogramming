#include <iostream>
#include <stdio.h>

using namespace std;

long long dp[35][2];

int main() {
    freopen("10918.inp", "r", stdin);
    freopen("10918.out", "w", stdout);
    dp[0][0] = dp[1][1] = 1;
    for (int i = 2; i <= 30; ++i)
        dp[i][0] = dp[i - 2][0] + 2 * dp[i - 1][1],
        dp[i][1] = dp[i - 1][0] + dp[i - 2][1];
    for (int n; cin >> n, n > -1;)
        cout << dp[n][0] << '\n';
}
