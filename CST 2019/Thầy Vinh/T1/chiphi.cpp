#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Edge;

int n, k, cnt;
bool vst[415];
int c[415][415], d[415];
vector<int> g[415];
pair<int, pair<int, int> > e[79815];
priority_queue<Edge, vector<Edge>, greater<Edge> > q;

int dijkstra (int s, int t)
{
    for (int i = 1; i <= n; i++) d[i] = 1000000000, vst[i] = 0;
    d[s] = 0;
    q.push({d[s], s});
    while (!q.empty())
    {
        Edge T = q.top(); q.pop();
        int u = T.second;
        if (T.first > d[u]) continue;
        vst[u] = 1;
        for (int i = 0; i < (int)g[u].size(); i++)
            if (!vst[g[u][i]] && T.first + c[u][g[u][i]] < d[g[u][i]])
            {
                d[g[u][i]] = T.first + c[u][g[u][i]];
                q.push({d[g[u][i]], g[u][i]});
            }
    }
    return d[t];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("chiphi.inp", "r", stdin);
    freopen("chiphi.out", "w", stdout);
    cin >> n >> k;
    int m = n * (n - 1) / 2, t = k;
    for (int i = 0; i < m; i++)
        cin >> e[i].second.first >> e[i].second.second >> e[i].first;
    sort(e, e + m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            c[i][j] = 1000000000;
    for (int i = 0; i < m; i++)
    {
        int u = e[i].second.first;
        int v = e[i].second.second;
        int dist = dijkstra(u, v);
        if (dist < e[i].first)
        {
            cout << "NO\n";
            return 0;
        }
        if (dist == e[i].first) continue;
        ++cnt;
        g[u].push_back(v);
        g[v].push_back(u);
        c[u][v] = c[v][u] = e[i].first;
    }
    if (cnt > k) cout << "NO\n";
        else cout << "YES\n";
    return 0;
}
