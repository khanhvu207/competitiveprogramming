#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, k, m;
long long dp[55][55];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("10721.inp", "r", stdin);
    freopen("10721.out", "w", stdout);
    while (cin >> n >> k >> m)
    {
        memset(dp, 0ll, sizeof dp);
        dp[0][0]=1ll;
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=m; ++j)
                for (int h=1; h<=k; ++h)
                    if (i-j>=0)
                        dp[i][h]+=dp[i-j][h-1];
        cout << dp[n][k] << '\n';
    }
}
