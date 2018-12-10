#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

int n, timer, articulationPoints;
int num[111], low[111];
bool vst[111];
vector<int> g[111];

void Input()
{
    for (int i=0; i<=101; ++i) g[i].clear();
    string line;
    getline(cin, line);
    while (true)
    {
        getline(cin, line);
        stringstream buffer(line);
        int node, adj;
        buffer >> node;
        if (node<1) break;
        while (buffer >> adj)
            g[node].push_back(adj),
            g[adj].push_back(node);
    }
}

void dfs(int u, int p=-1)
{
    vst[u]=true;
    num[u]=low[u]=++timer;
    int children=0;
    for (int i=0; i<(int)g[u].size(); ++i)
    {
        int v=g[u][i];
        if (v==p) continue;
        if (vst[v])
            low[u]=min(low[u], num[v]);
        else
        {
            dfs(v);
            low[u]=min(low[u], low[v]);
            if (low[v]>=num[u] && p!=-1)
                ++articulationPoints;
            children++;
        }
    }
    if (p==-1 && children>1)
        ++articulationPoints;
}

void Solve()
{
    memset(vst, false, sizeof vst);
    memset(num, -1, sizeof num);
    memset(low, -1, sizeof low);
    timer=0;
    articulationPoints=0;
    for (int u=1; u<=n; ++u)
        if (!vst[u]) dfs(u);
    cout << articulationPoints << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("315.inp", "r", stdin);
    freopen("315.out", "w", stdout);
    while (cin >> n)
    {
        if (n<1) return 0;
        Input();
        Solve();
    }
}
