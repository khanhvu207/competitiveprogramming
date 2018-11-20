#include <iostream>
#include <cstdio>
using namespace std;

int n, a[100015], b[100015], c[100015];
int dp[7][100015][3][4];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("acm.inp", "r", stdin);
    freopen("acm.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=1; i<=n; i++) cin >> c[i];
    ///A=0, B=1, C=2;
    for (int p=1; p<=6; p++)
        for (int i=1; i<=n; i++)
            for (int j=0; j<3; j++)
                for (int k=1; k<=3; k++)
                    dp[p][i][j][k]=1000000;
    dp[1][0][0][1]=0;
    dp[2][0][0][1]=0;
    dp[3][0][1][1]=0;
    dp[4][0][1][1]=0;
    dp[5][0][2][1]=0;
    dp[6][0][2][1]=0;
    for (int i=1; i<=n; i++)
    {
        ///ABC
        dp[1][i][0][1]=dp[1][i-1][0][1]+a[i];
        if (i>1) dp[1][i][1][2]=min(dp[1][i-1][1][2]+b[i], dp[1][i-1][0][1]+b[i]);
        if (i>2) dp[1][i][2][3]=min(dp[1][i-1][2][3]+c[i], dp[1][i-1][1][2]+c[i]);
        ///ACB
        dp[2][i][0][1]=dp[2][i-1][0][1]+a[i];
        if (i>1) dp[2][i][2][2]=min(dp[2][i-1][2][2]+c[i], dp[2][i-1][0][1]+c[i]);
        if (i>2) dp[2][i][1][3]=min(dp[2][i-1][1][3]+b[i], dp[2][i-1][2][2]+b[i]);
        ///BAC
        dp[3][i][1][1]=dp[3][i-1][1][1]+b[i];
        if (i>1) dp[3][i][0][2]=min(dp[3][i-1][0][2]+a[i], dp[3][i-1][1][1]+a[i]);
        if (i>2) dp[3][i][2][3]=min(dp[3][i-1][2][3]+c[i], dp[3][i-1][0][2]+c[i]);
        ///BCA
        dp[4][i][1][1]=dp[4][i-1][1][1]+b[i];
        if (i>1) dp[4][i][2][2]=min(dp[4][i-1][2][2]+c[i], dp[4][i-1][1][1]+c[i]);
        if (i>2) dp[4][i][0][3]=min(dp[4][i-1][0][3]+a[i], dp[4][i-1][2][2]+a[i]);
        ///CAB
        dp[5][i][2][1]=dp[5][i-1][2][1]+c[i];
        if (i>1) dp[5][i][0][2]=min(dp[5][i-1][0][2]+a[i], dp[5][i-1][2][1]+a[i]);
        if (i>2) dp[5][i][1][3]=min(dp[5][i-1][1][3]+b[i], dp[5][i-1][0][2]+b[i]);
        ///CBA
        dp[6][i][2][1]=dp[6][i-1][2][1]+c[i];
        if (i>1) dp[6][i][1][2]=min(dp[6][i-1][1][2]+b[i], dp[6][i-1][2][1]+b[i]);
        if (i>2) dp[6][i][0][3]=min(dp[6][i-1][0][3]+a[i], dp[6][i-1][1][2]+a[i]);
    }
    int res=100000000;
    for (int p=1; p<=6; p++)
        for (int i=0; i<3; i++)
            res=min(res, dp[p][n][i][3]);
    cout << res;
    return 0;
}
