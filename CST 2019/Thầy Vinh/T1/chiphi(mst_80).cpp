#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k;
int r[415], p[415], v[415][415];
pair<int, pair<int, int> > e[79815];
bool mark[79815];

bool joint (int u, int v)
{
    while (p[u] != u) p[u] = p[p[u]], u = p[u];
    while (p[v] != v) p[v] = p[p[v]], v = p[v];
    if (u == v) return false;
    if (r[u] > r[v])
        r[u] += r[v], p[v] = u;
    else
        r[v] += r[u], p[u] = v;
    return true;
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
    for (int i = 0; i < m; i++) mark[i] = 0;
    for (int i = 1; i <= n; i++) r[i] = 1, p[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            v[i][j] = 1000000000;
    for (int i = 0; i < m && t > 0; i++)
        if (joint(e[i].second.first, e[i].second.second))
            v[e[i].second.first][e[i].second.second] = e[i].first,
            v[e[i].second.second][e[i].second.first] = e[i].first,
            t--, mark[i] = 1;
    for (int i = 0; i < m && t > 0; i++)
        if (!mark[i])
            v[e[i].second.first][e[i].second.second] = e[i].first,
            v[e[i].second.second][e[i].second.first] = e[i].first,
            t--;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (i != j && j != k && i != k)
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
    for (int i = 0; i < m; i++)
        if (e[i].first < v[e[i].second.first][e[i].second.second])
        {
            cout << "NO\n";
            return 0;
        }
    cout << "YES\n";
    return 0;
}
