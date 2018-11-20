#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, m, k, d[515][60015], cost[515][515];
bool f[515], vst[515][60015];
vector<int> g[515];
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("vanchuyen.inp", "r", stdin);
    freopen("vanchuyen.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0, x; i < k; i++)
        cin >> x, f[x]=1;
    cin >> m;
    for (int i = 0, u, v, c; i < m; i++)
        cin >> u >> v >> c,
        cost[u][v] = c,
        cost[v][u] = c,
        g[u].push_back(v),
        g[v].push_back(u);

    q.push({0, {1, 600}});
    for (int i = 1; i <= n; i++)
        for (int f = 0; f <= 6000; f++)
            d[i][f] = 1000000000;
    d[1][600]=0;
    while (!q.empty())
    {
        pair<int, pair<int, int> > top=q.top(); q.pop();
        if (top.first > d[top.second.first][top.second.second]) continue;
        int c = top.first;
        int u = top.second.first;
        int rf = top.second.second;
        vst[u][rf] = 1;
        for (int i = 0; i < (int)g[u].size(); i++)
        {
            int v = g[u][i];
            if (f[u] && cost[u][v] > rf && !vst[v][600 - cost[u][v]] && c + 1 < d[v][600 - cost[u][v]])
            {
                d[v][600 - cost[u][v]] = c + 1;
                q.push({d[v][600 - cost[u][v]], {v, 600 - cost[u][v]}});
                continue;
            }
            if (cost[u][v] <= rf)
            {
                if (f[u] && !vst[v][600 - cost[u][v]] && c + 1 < d[v][600 - cost[u][v]])
                {
                    d[v][600 - cost[u][v]] = c + 1;
                    q.push({d[v][600 - cost[u][v]], {v, 600 - cost[u][v]}});
                }
                if (!vst[v][rf - cost[u][v]] && c < d[v][rf - cost[u][v]])
                {
                    d[v][rf - cost[u][v]] = c;
                    q.push({d[v][rf - cost[u][v]], {v, c}});
                }
            }
        }
    }
    int res = 1000000000;
    for (int i = 0; i <= 6000; i++)
        res = min(res, d[n][i]);
    if (res == 1000000000)
        cout << -1;
    else
        cout << res;
    return 0;
}
