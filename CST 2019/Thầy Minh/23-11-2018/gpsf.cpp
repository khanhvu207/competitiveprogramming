#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int t, n, m, dp[515][515][3];
string a, b, s, p;

int cost (char a, char b)
{
    return (a == b ? 2 : -1);
}

int solve (int i, int j, int state)
{
    if (dp[i][j][state] != -1) return dp[i][j][state];
    if (i == n + 1 && j == m + 1) return 0;
    int res = -1e9;
    if (i <= n && j <= m) res = max(res, solve(i + 1, j + 1, 0) + cost(a[i], b[j]));
    if (j <= m) res = max(res, solve(i, j + 1, 1) + (state != 1 ? -5 : -1));
    if (i <= n) res = max(res, solve(i + 1, j, 2) + (state != 2 ? -5 : -1));
    dp[i][j][state] = res;
    return res;
}

void tracing (int i, int j, int state)
{
    if (i == n + 1 && j == m + 1) return;
    int x = -1e9, y = -1e9, z = -1e9;
    if (i <= n && j <= m) x = dp[i + 1][j + 1][0] + cost(a[i], b[j]);
    if (j <= m) y = dp[i][j + 1][1] + (state != 1 ? -5 : -1);
    if (i <= n) z = dp[i + 1][j][2] + (state != 2 ? -5 : -1);
    int opt = max(x, max(y, z));
    if (opt == x)
    {
        s = s + a[i];
        p = p + b[j];
        tracing(i + 1, j + 1, 0);
    } else if (opt == y)
    {
        s = s + '-';
        p = p + b[j];
        tracing(i, j + 1, 1);
    } else 
    {
        p = p + '-';
        s = s + a[i];
        tracing(i + 1, j, 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("gpsf.inp", "r", stdin);
    freopen("gpsf.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        n = a.size();
        m = b.size();
        a = '$' + a;
        b = '$' + b;
        memset(dp, -1, sizeof dp);
        dp[n + 1][m + 1][0] = 0;
        dp[n + 1][m + 1][1] = 0;
        dp[n + 1][m + 1][2] = 0;
        cout << solve(1, 1, 0) << '\n';
        s = "";
        p = "";
        tracing(1, 1, 0);
        cout << s << '\n' << p << '\n';
    }
    return 0;
}
