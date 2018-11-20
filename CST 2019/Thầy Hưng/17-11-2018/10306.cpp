#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n, s, dp[315][315], a[45], b[45];

bool chk (int x)
{
    return floor(sqrt(x))*floor(sqrt(x))==x;
}

int solve (int x, int y)
{
    if (dp[x][y]!=-1) return dp[x][y];
    if (x==0&&y==0) return 0;
    int cnt=1e9;
    for (int i=0; i<n; ++i)
        if (x>=a[i]&&y>=b[i])
            cnt=min(cnt, solve(x-a[i], y-b[i])+1);
    dp[x][y]=cnt;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("10306.inp", "r", stdin);
    freopen("10306.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        for (int i=0; i<n; ++i)
            cin >> a[i] >> b[i];
        memset(dp, -1, sizeof dp);
        int ans=1e9;
        for (int i=0; i<=s*s; ++i)
        {
            if (!chk(i)||!chk(s*s-i)) continue;
            ans=min(ans, solve(sqrt(i), sqrt(s*s-i)));
            ans=min(ans, solve(sqrt(s*s-i), sqrt(i)));
        }
        if (ans==1e9)
            cout << "not possible\n";
        else
            cout << ans << '\n';
    }
    return 0;
}
