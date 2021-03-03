#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int t, a, b, c, x[25][25][25];
long long dp[25][25][25];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("10755.inp", "r", stdin);
    freopen("10755.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        for (int i=1; i<=a; i++)
            for (int j=1; j<=b; j++)
                for (int k=1; k<=c; k++)
                    cin >> x[i][j][k];
        memset(dp, 0, sizeof dp);
        for (int layer=1; layer<=a; layer++)
            for (int y=1; y<=b; y++)
                for (int z=1; z<=c; z++)
                    dp[layer][y][z]=x[layer][y][z]+dp[layer][y-1][z]+dp[layer][y][z-1]-dp[layer][y-1][z-1];
        long long res=-1e18;
        for (int yr=1; yr<=b; yr++)
            for (int zr=1; zr<=c; zr++)
                for (int yl=yr; yl>=1; yl--)
                    for (int zl=zr; zl>=1; zl--)
                    {
                        long long val=-1e18;
                        for (int layer=1; layer<=a; layer++)
                            val=max(val, 0ll)+dp[layer][yr][zr]-dp[layer][yr][zl-1]-dp[layer][yl-1][zr]+dp[layer][yl-1][zl-1],
                            res=max(res, val);
                    }
        cout << res << '\n';
    }
    return 0;
}
