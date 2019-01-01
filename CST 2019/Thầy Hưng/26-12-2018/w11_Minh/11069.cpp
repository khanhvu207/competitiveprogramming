#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    freopen("11069.inp", "r", stdin);
    freopen("11069.out", "w", stdout);
    int dp[80];
    dp[0] = 0; dp[1] = 1; dp[2] = 1;
    for (int i = 3; i <= 76; ++i)
        dp[i] = dp[i - 2] + dp[i - 3];
    for (int n; cin >> n;)
        cout << dp[n] + dp[n - 1] << '\n';
}
