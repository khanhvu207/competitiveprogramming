#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
const long long oo = 1e18;
typedef pair <long long, int> ii;
typedef pair <ii, long long> iii;
int n, m, u, v;
long long d[N], D, c;
vector <ii> adj[N];

void dijkstra()
{
    int u, v;
    long long du, uv, pu;
    priority_queue < iii, vector <iii>, greater <iii> > pq;

    for (int i = 1; i <= n; i++) d[i] = oo;
    d[1] = 0;
    pq.push({{0, 1}, -oo});

    while (!pq.empty())
    {
        u = pq.top().first.second;
        du = pq.top().first.first;
        pu = pq.top().second;
        pq.pop();

        for (ii p : adj[u])
        {
            uv = p.first;
            v = p.second;
            if (uv - pu >= D) pq.push({{du + uv, v}, uv});
            if (uv - pu >= D && d[v] > du + uv) d[v] = du + uv;
        }
    }
}

int main()
{
    freopen("DANANG.INP", "r", stdin);
    freopen("DANANG.OUT", "w", stdout);

    scanf("%d%d%d", &n, &m, &D);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }

    dijkstra();

    cout << (d[n] != oo ? d[n] : -1);

    return 0;
}
