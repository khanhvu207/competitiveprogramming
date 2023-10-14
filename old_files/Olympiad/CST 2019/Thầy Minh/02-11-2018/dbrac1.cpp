#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, k;
long long dp[80][80][80];

long long solve (int i, int open, int lv)
{
    if (dp[i][open][lv]!=-1ll) return dp[i][open][lv];
    if (i>n)
        return (open==0&&lv==k)*1ll;
    dp[i][open][lv]=0ll;
    dp[i][open][lv]+=solve(i+1, open+1, max(lv, open+1));
    if (open>0) dp[i][open][lv]+=solve(i+1, open-1, max(lv, open-1));
    return dp[i][open][lv];
}

int main()
{
    freopen("dbrac1.inp", "r", stdin);
    freopen("dbrac1.out", "w", stdout);
    while (scanf("%d%d", &n, &k)==2)
    {
        n*=2;
        memset(dp, -1ll, sizeof dp);
        printf("%I64d\n", solve(1, 0, 0));
    }
    return 0;
}
