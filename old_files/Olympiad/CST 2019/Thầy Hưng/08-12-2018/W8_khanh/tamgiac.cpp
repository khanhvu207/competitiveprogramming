#include <iostream>
#include <cstdio>
using namespace std;

int n, res;
int a[111], dp[2][111][555];
bool t[111][555];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("tamgiac.inp", "r", stdin);
    freopen("tamgiac.out", "w", stdout);
    cin >> n;
    a[0] = 1;
    for (int i = 1; i <= n; ++i) a[i] = a[i - 1] + 2;
    for (int i = 1; i <= n; ++i)
    {
        string line;
        cin >> line;
        for (int j = 0; j < a[n - i]; ++j)
            t[i][j + i] = (line[j] == '-');
    }
    for (int i = 1; i <= a[n - 1]; ++i)
        dp[0][1][i] = t[1][i];
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j < a[n - i]; ++j)
        {
            if (j & 1) continue;
            if (!t[i][j + i]) dp[0][i][j + i] = 0;
                else dp[0][i][j + i] = 1;
            dp[0][i][j + i] = max(dp[0][i][j + i], min(dp[0][i - 1][j + i - 1], dp[0][i - 1][j + i + 1]) + 1);
            if (!t[i - 1][j + i]) dp[0][i][j + i] = t[i][j + i];
            res = max(res, dp[0][i][j + i]);
        }
    for (int j = 0; j < a[0]; ++j)
        dp[1][n][j + n] = t[n][j + n];
    for (int i = n - 1; i >= 1; --i)
        for (int j = 0; j < a[n - i]; ++j)
        {
            if (!(j & 1)) continue;
            if (!t[i][j + i]) dp[1][i][j + i] = 0;
                else dp[1][i][j + i] = 1;
            dp[1][i][j + 1] = max(dp[1][i][j + i], min(dp[1][i + 1][j + i - 1], dp[1][i + 1][j + i + 1]) + 1);
            if (!t[i + 1][j + i]) dp[1][i][j + i] = t[i][j + i];
            res = max(res, dp[1][i][j + i]);
        }
    long long sum = 0;
    for (int i = 0; i < res; ++i)
        sum += a[i];
    cout << sum;
}

//#-##----#
// -----#-
//  ---#-
//   -#-
//    -

