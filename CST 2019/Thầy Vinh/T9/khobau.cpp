#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
const int dx[4]={-1, 0, 1, 0};
const int dy[4]={0, 1, 0, -1};
#define prev prevv

int n, m;
int a[1111][1111][10], lab[1111][1111];
vector<vector<int> > g;
long long h[1000015];
int p[50][1000015];
bool vst[1000015];

void dfs(int u, int prev)
{
    for (int i=0; i<(int)g[u].size(); ++i)
        if (g[u][i]!=prev)
        {
            h[g[u][i]]=h[u]+1;
            p[0][g[u][i]]=u;
            dfs(g[u][i], u);
        }
}

int lca(int u, int v)
{
    if (h[u]<h[v]) swap(u, v);
    for (int i=log2(h[u])+1; i>=0; --i)
        if (h[p[i][u]]>=h[v]) u=p[i][u];
    if (u==v) return u;
    for (int i=log2(h[u])+1; i>=0; --i)
        if (p[i][u]!=p[i][v])
            u=p[i][u], v=p[i][v];
    return p[0][u];
}

int main()
{
    freopen("khobau.inp", "r", stdin);
    cin >> n >> m;
    string line;
    getline(cin, line);
    for (int i=0; i<=n; ++i)
    {
        getline(cin, line);
        for (int j=0; j<(int)line.size(); ++j)
        {
            if (line[j]==' ') continue;
            if (j%2==0) ///vertical walls
            {
                a[i][j/2][2]=true;
                a[i][j/2+1][8]=true;
            } else ///horizontal walls
            {
                int col=j/2+1;
                a[i][col][4]=true;
                a[i+1][col][1]=true;
            }
        }
    }
    int c=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            lab[i][j]=++c;
    g.resize(c+5);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            for (int k=0; k<4; ++k)
            {
                int x=i+dx[k];
                int y=j+dy[k];
                if (x<1 || x>n || y<1 || y>m || !(!a[i][j][1<<k] && !a[x][y][1<<((k+2)%4)])) continue;
                g[lab[i][j]].push_back(lab[x][y]);
            }
    h[lab[1][1]]=1ll;
    memset(p, -1, sizeof p);
    dfs(lab[1][1], -1);

    for (int i=1; (1<<i)<=c; ++i)
        for (int u=1; u<=c; ++u)
            p[i][u]=p[i-1][p[i-1][u]];
    int q;
    cin >> q;
    vector<pair<int, int> > b;
    for (int i=0, u, v; i<q; ++i)
        b.push_back({u, v})
}

/// _ _ _ _ _
///|_ _  |_  |
///|  _| |  _|
///| |_   _| |
///|    _ _  |
///|_|_ _ _|_|

