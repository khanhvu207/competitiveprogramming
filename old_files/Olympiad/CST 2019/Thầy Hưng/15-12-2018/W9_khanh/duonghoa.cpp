#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int inf = 1e9;
const int N = 10015;

int n, m, s, t, res, d[N];
bool vis[N];
vector<pair<int, int> > a[N], trace[N];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap;

void tracing(int v)
{
    if (v == 0) return;
    vis[v] = true;
    for (int i = 0; i < (int)trace[v].size(); ++i)
    {
        int u = trace[v][i].first;
        int c = trace[v][i].second;
        res += c;
        if (!vis[u]) tracing(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("duonghoa.inp", "r", stdin);
    freopen("duonghoa.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].push_back({v, c});
        a[v].push_back({u, c});
    }
    s = 0, t = n - 1;

    for (int i = 0; i <= t; ++i) d[i] = inf;
    d[s] = 0;
    heap.push({d[s], s});
    while (!heap.empty())
    {
        int cost = heap.top().first;
        int u = heap.top().second;
        heap.pop();
        if (cost > d[u]) continue;
        vis[u] = true;
        for (int i = 0; i < (int)a[u].size(); ++i)
        {
            int v = a[u][i].first;
            int c = a[u][i].second;
            if (cost + c == d[v])
            {
                trace[v].push_back({u, c});
            } else if (!vis[v] && cost + c < d[v])
            {
                trace[v].clear();
                d[v] = cost + c;
                heap.push({d[v], v});
                trace[v].push_back({u, c});
            }
        }
    }
    for (int i = 0; i <= t; ++i) vis[i] = false;
    tracing(t);
    cout << res * 2;
}
