#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const long long inf=1e9;
#define dp(u, d) dp[u][d+300]

int n, d;
bool w[333], leaf[333];
vector<int> g[333];
long long dp[333][1111];

void Input()
{
    memset(w, 0, sizeof w);
    memset(leaf, 0, sizeof leaf);
    cin >> n >> d;
    for (int i=0; i<n; ++i)
    {
        int id, m;
        cin >> id;
        cin >> w[id] >> m;
        if (m<1) leaf[id]=true;
        for (int j=0, v; j<m; ++j)
        {
            cin >> v;
            g[id].push_back(v);
        }
    }
}

long long solve(int u, int d)
{
    if (max(d, -d)>n) return inf;
    if (dp(u, d)>-1ll) return dp(u, d);
    if ((int)g[u].size())
    {
        dp(u, d)=d?inf:1ll;
        if ((int)g[u].size()==1)
            dp(u, d)=min(dp(u, d), solve(g[u][0], d+(w[u]?-1:1)));
        else {
            for (int i=-n; i<=n; ++i)
                dp(u, d)=min(dp(u, d), solve(g[u][0], i)+solve(g[u][1], d+(w[u]?-1:1)-i));
        }
    } else
    {
        if (d==0) dp(u, d)=1ll;
            else if ((w[u]&&d==1) || (!w[u]&&d==-1)) dp(u, d)=0ll;
                else dp(u, d)=inf;
    }
    return dp(u, d);
}

void Solve()
{
    memset(dp, -1ll, sizeof dp);
    cout << (solve(0, d)<inf?dp(0, d):-1) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("prune.inp", "r", stdin);
    freopen("prune.out", "w", stdout);
    Input();
    Solve();
}
