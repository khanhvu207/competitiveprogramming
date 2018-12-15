#include <iostream>
#include <cstdio>
using namespace std;

int n, m, g[5111][5111], dp[5111][5111];

bool chk (int x, int y, int d)
{
    int lx = max(0, x - d);
    int ly = max(0, y - d);
    int rx = min(5000, x + d);
    int ry = min(5000, y + d);

    int sum = dp[rx][ry] - (lx < 1 ? 0 : dp[lx - 1][ry]) - (ly - 1 < 0 ? 0 : dp[rx][ly - 1]) + (lx < 1 || ly < 1 ? 0 : dp[lx - 1][ly - 1]);
    return sum > 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("anninh.inp", "r", stdin);
    freopen("anninh.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0, x, y; i < n; ++i)
        cin >> x >> y, g[x][y] = 1;
    for (int i = 0; i <= 5000; ++i)
        for (int j = 0; j <= 5000; ++j)
            dp[i][j] = g[i][j] + (i < 1 ? 0 : dp[i - 1][j]) + (j < 1 ? 0 : dp[i][j - 1]) - (i < 1 || j < 1 ? 0 : dp[i - 1][j - 1]);
    while (m--)
    {
        int u, v;
        cin >> u >> v;

        int l = 0, r = 5000, res = 0;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (chk(u, v, m)) r = m - 1, res = m;
                else l = m + 1;
        }
        cout << res << '\n';
    }
}
