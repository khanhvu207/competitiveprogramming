#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, h[5111], nxt[5111], agents=0;
bool mark[5111][5111];
vector<bool> vst;
vector<int> g[5111];

void dfs (int u)
{
    if (u==n) return;
    mark[u][nxt[u]]=1;
    dfs(nxt[u]);
}

void update (int u)
{
    vst[u]=1;
    h[u]=0;
    for (int i=0; i<(int)g[u].size(); ++i)
    {
        if (!vst[g[u][i]]) update(g[u][i]);
        int tmp=!mark[u][g[u][i]]+h[g[u][i]];
        if (tmp>=h[u])
            h[u]=tmp, nxt[u]=g[u][i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("nar.inp", "r", stdin);
    freopen("nar.out", "w", stdout);
    cin >> n;
    for (int i=1; i<n; ++i)
    {
        int m; cin >> m;
        for (int j=0, v; j<m; ++j)
            cin >> v, g[i].push_back(v);
    }
    vst.resize(n+1, 0);
    for (int i=1; i<=n; ++i) vst[i]=0;
    update(1);
    while (true)
    {
        if (h[1]<1) break;
        dfs(1);
        ++agents;
        for (int i=1; i<=n; ++i) vst[i]=0;
        update(1);
    }
    cout << agents;
    return 0;
}
