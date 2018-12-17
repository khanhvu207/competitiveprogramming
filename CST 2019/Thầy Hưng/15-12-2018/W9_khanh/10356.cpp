#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int N = 555;
const int inf = 1e9;
typedef pair<int, pair<int, bool> > state;

int n, m, cost[N][N], d[N][2];
bool vis[N][2];
vector<int> a[N];
priority_queue<state, vector<state>, greater<state> > heap;

void dijkstra()
{
    int s = 0, t = n - 1;
    for (int i = 0; i < n; ++i)
    {
        d[i][0] = d[i][1] = inf;
        vis[i][0] = vis[i][1] = false;
    }
    d[s][0] = 0;
    heap.push({d[s][0], {s, 1}});
    while (!heap.empty())
    {
        int dist = heap.top().first;
        int u = heap.top().second.first;
        int bike = heap.top().second.second;
        heap.pop();
        if (dist > d[u][bike]) continue;
        vis[u][bike] = true;
        for (int i = 0; i < (int)a[u].size(); ++i)
        {
            int v = a[u][i];
            if (!vis[v][bike ^ 1] && dist + cost[u][v] < d[v][bike ^ 1])
            {
                d[v][bike ^ 1] = dist + cost[u][v];
                heap.push({d[v][bike ^ 1], {v, bike ^ 1}});
            }
        }
    }
    if (d[t][1] == inf)
        cout << "?\n";
    else
        cout << d[t][1] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("10356.inp", "r", stdin);
    freopen("10356.out", "w", stdout);

    int tc = 0;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; ++i) a[i].clear();
        for (int i = 0, u, v, x; i < m; ++i)
        {
            cin >> u >> v >> x;
            a[u].push_back(v);
            a[v].push_back(u);
            cost[u][v] = cost[v][u] = x;
        }
        cout << "Set #" << ++tc << '\n';
        dijkstra();
    }
}
