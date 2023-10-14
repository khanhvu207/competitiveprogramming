#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n, m, k, l, r=0, b=0, timer=0, cnt=0;
int tin[100015], fup[100015], sblue[100015], sred[100015];
bool vst[100015], red[100015], blue[100015];
vector<int> g[100015];

void dfs (int v, int p)
{
    vst[v]=1;
    tin[v]=fup[v]=timer++;
    for (int i=0; i<(int)g[v].size(); i++)
    {
        int u=g[v][i];
        if (u==p) continue;
        if (vst[u])
            fup[v]=min(fup[v], tin[u]);
        else
        {
            dfs(u, v);
            fup[v]=min(fup[v], fup[u]);
            if (fup[u]>tin[v])
            {
                int blue_u=sblue[u];
                int blue_v=b-blue_u;
                int red_u=sred[u];
                int red_v=r-red_u;
                if ((blue_u<1&&blue_v>=1)||(red_u<1&&red_v>=1)||(blue_u>=1&&blue_v<1)||(red_u>=1&&red_v<1)) ++cnt;
            }
            sblue[v]+=sblue[u];
            sred[v]+=sred[u];
        }
    }
    sblue[v]+=blue[v];
    sred[v]+=red[v];
}

int main()
{
    freopen("mgt.inp", "r", stdin);
    freopen("mgt.out", "w", stdout);
    cin >> n >> m >> k >> l;
    for (int i=0, x; i<k; i++)
        cin >> x, red[x]=1, ++r;
    for (int i=0, x; i<l; i++)
        cin >> x, blue[x]=1, ++b;
    for (int i=0, u, v; i<m; i++)
        cin >> u >> v,
        g[u].push_back(v),
        g[v].push_back(u);
    memset(tin, -1, sizeof tin);
    memset(fup, -1, sizeof fup);
    for (int i=1; i<=n; i++)
        if (!vst[i]) dfs(i, -1);
    cout << cnt;
    return 0;
}
