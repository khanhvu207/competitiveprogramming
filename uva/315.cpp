#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

int n, timer, articulationPoints;
int num[333], low[333];
bool vst[333], critical[333];
vector<int> g[333];

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
            dfs(v, u);
            low[u]=min(low[u], low[v]);
            if (low[v]>=num[u] && p!=-1)
                critical[u]=true;
            children++;
        }
    }
    if (p==-1 && children>1)
        critical[u]=true;
}

void Solve()
{
    memset(vst, false, sizeof vst);
    memset(critical, false, sizeof critical);
    memset(num, -1, sizeof num);
    memset(low, -1, sizeof low);
    timer=0;
    articulationPoints=0;
    for (int u=1; u<=n; ++u)
        if (!vst[u]) dfs(u);
    for (int u=1; u<=n; ++u)
        articulationPoints += critical[u];
    cout << articulationPoints << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n)
    {
        if (n<1) return 0;
        Input();
        Solve();
    }
}
