#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, c;
    Edge (int uu, int cc)
    {
        this->u = uu;
        this->c = cc;
    }
    bool operator < (const Edge &r) const
    {
        return c > r.c;
    }
};
int n, m, sum = 0;
int d[10015], dp[10015];
bool vst[10015];
vector<vector<int> > c;
vector<pair<int, int> > g[10015];
priority_queue<Edge> q;
vector<pair<int, int> > parent[10015];

void tracing (int u)
{
    if (u == 0) return;
    vst[u] = 1;
    for (int i = 0; i < (int)parent[u].size(); i++)
    {
        sum += parent[u][i].second;
        if (!vst[parent[u][i].first]) tracing(parent[u][i].first);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("trongcay.inp", "r", stdin);
    freopen("trongcay.out", "w", stdout);
    cin >> n >> m;
    c.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 0, u, v, cc; i < m; i++)
        cin >> u >> v >> cc,
            g[u].push_back({v, cc}),
            g[v].push_back({u, cc});
    memset(vst, 0, sizeof vst);
    for (int i = 0; i < n; i++) d[i] = 1000000000;
    d[0] = 0;
    q.push(Edge(0, d[0]));
    while (!q.empty())
    {
        Edge T = q.top(); q.pop();
        if (T.c > d[T.u]) continue;
        vst[T.u] = 1;
        for (int i = 0; i < (int)g[T.u].size(); i++)
        {
            int v = g[T.u][i].first;
            int cost = g[T.u][i].second;
            if (T.c + cost == d[v])
                parent[v].push_back({T.u, cost});
            else if (!vst[v] && T.c + cost < d[v])
                parent[v].clear(),
                parent[v].push_back({T.u, cost}),
                d[v] = T.c + cost,
                q.push(Edge(v, d[v]));
        }
    }
    memset(vst, 0, sizeof vst);
    tracing(n - 1);
    cout << 2 * sum;
    return 0;
}
