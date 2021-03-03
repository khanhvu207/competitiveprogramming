#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, s, res[1015];
vector<int> adj[1015];
bool w[1015];

void dfs (int u, int p, int h)
{
    int child = 0;
    for (int i = 0; i < (int)adj[u].size(); ++i)
        if (adj[u][i] != p) dfs(adj[u][i], u, h + 1), ++child;

    if (child < 1)
    {
        w[u] = h & 1;
        res[u] = u;
    }
    else
    {
        if (h % 2 == 0)
        {
            int c = 1111;
            for (int i = 0; i < (int)adj[u].size(); ++i)
                if (w[adj[u][i]] && adj[u][i] != p) c = min(c, adj[u][i]);
            if (c != 1111)
                w[u] = 1, res[u] = c;
        } else
        {
            int c = 1111;
            bool flag = 1;
            for (int i = 0; i < (int)adj[u].size(); ++i)
                if (adj[u][i] != p && !w[adj[u][i]]) flag = 0;
                    else c = min(c, res[adj[u][i]]);
            w[u] = flag;
            res[u] = c;
        }
    }
}

int main()
{
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n >> s;
    for (int i = 0, u, v; i < n - 1; ++i)
        cin >> u >> v,
        adj[u].push_back(v),
        adj[v].push_back(u);

    dfs(s, -1, 0);
    if (!w[s]) cout << -1;
        else cout << res[s];
}
