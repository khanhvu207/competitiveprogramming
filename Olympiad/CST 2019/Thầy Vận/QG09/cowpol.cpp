#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n, k;
int h[200111], p[20][200111];
vector<int> party[100111];
vector<int> g[200111];

void Input()
{
    cin >> n >> k;
    for (int i=1, a, b; i<=n; ++i)
    {
        cin >> a >> b;
        party[a].push_back(i);
        g[i].push_back(b);
        g[b].push_back(i);
        p[0][i]=b;
    }
}

void dfs(int u, int p)
{
    for (int i=0; i<(int)g[u].size(); ++i)
        if (g[u][i]!=p)
        {
            h[g[u][i]]=h[u]+1;
            dfs(g[u][i], u);
        }
}

void constructLCA()
{
    h[0]=1;
    dfs(0, -1);
    for (int i=1; (1<<i)<=n; ++i)
        for (int u=0; u<=n; ++u)
            p[i][u]=p[i-1][p[i-1][u]];
}

int LCA(int u, int v)
{
    if (h[u]<h[v]) swap(u, v);
    for (int i=log2(h[u]); i>=0; --i)
        if (h[p[i][u]]>=h[v]) u=p[i][u];
    if (u==v) return u;
    for (int i=log2(h[u]); i>=0; --i)
        if (p[i][u]!=p[i][v])
            u=p[i][u], v=p[i][v];
    return p[0][u];
}

void Solve()
{
    constructLCA();
    for (int pt=1; pt<=k; ++pt)
    {
        int u=party[pt][0], v, hmax=0;
        for (int i=1; i<(int)party[pt].size(); ++i)
        {
            int x=LCA(u, party[pt][i]);
            if (h[u]+h[party[pt][i]]-2*h[x]>hmax)
                hmax=h[u]+h[party[pt][i]]-2*h[x],
                v=party[pt][i];
        }
        for (int i=0; i<(int)party[pt].size(); ++i)
            if (party[pt][i]!=v)
            {
                int x=LCA(v, party[pt][i]);
                hmax=max(hmax, h[v]+h[party[pt][i]]-2*h[x]);
            }
        cout << hmax << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("cowpol.inp", "r", stdin);
    freopen("cowpol.out", "w", stdout);
    Input();
    Solve();
}
