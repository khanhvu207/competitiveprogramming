#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, k;
long long dp[100][100][100];

long long solve (int i, int open, int lv)
{
    //cerr<<i<<' '<<open<<' '<<lv<<'\n';
    if (dp[i][open][lv]!=-1ll) return dp[i][open][lv];
    if (i>n)
        return (open==0&&lv==k)*1ll;
    dp[i][open][lv]=0ll;
    dp[i][open][lv]+=solve(i+1, open+1, max(lv, open+1));
    if (open>0) dp[i][open][lv]+=solve(i+1, open-1, max(lv, open-1));
    return dp[i][open][lv];
}

void trace (long long order, int cur, int open, int lv)
{
    if (cur>n) return;
    long long t=solve(cur+1, open+1, max(lv, open+1));
    if (t>=order)
    {
        cout << '(';
        trace(order, cur+1, open+1, max(lv, open+1));
        return;
    } else
    {
        order-=t;
        cout << ')';
        trace(order, cur+1, open-1, max(lv, open-1));
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("gendbrac.inp", "r", stdin);
    freopen("gendbrac.out", "w", stdout);
    cin >> n >> k;
    n*=2;
    memset(dp, -1ll, sizeof dp);
    solve(1, 0, 0);
    for (long long i=0ll; i<min(30000ll, dp[1][0][0]); i++)
    {
        trace(i+1ll, 1, 0, 0);
        cout << '\n';
    }
    return 0;
}

