#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, dp[1015];
bool vst[1015];
vector<int> topo;
vector<pair<int, int> > g[1015];

void dfs (int u)
{
    vst[u]=1;
    for (int i=0; i<(int)g[u].size(); ++i)
        if (!vst[g[u][i].first]) dfs(g[u][i].first);
    topo.push_back(u);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("dulich.inp", "r", stdin);
    freopen("dulich.out", "w", stdout);
    cin >> n >> m;
    for (int i=0, u, v, c; i<m; ++i)
    {
        cin >> u >> v >> c;
        g[u].push_back(make_pair(v, c));
    }
    for (int i=1; i<=n; ++i)
        if (!vst[i]) dfs(i);
    reverse(topo.begin(), topo.end());
    int res=0;
    for (int i=topo.size()-1; i>=0; --i)
        for (int j=0; j<(int)g[topo[i]].size(); ++j)
        {
            dp[topo[i]]=max(dp[topo[i]], dp[g[topo[i]][j].first]+g[topo[i]][j].second);
            res=max(res, dp[topo[i]]);
        }
    cout << res;
    return 0;
}
