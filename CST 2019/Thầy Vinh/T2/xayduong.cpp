#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
const double eps = 1e-6;
typedef pair<double, pair<int, int> > Edges;
int n, m;
int r[1015], p[1015];
bool has[1015][1015];
double dist[1015][1015], sum = 0.0;
pair<double, double> points[1015];
vector<Edges> e;

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
    freopen("xayduong.inp", "r", stdin);
    freopen("xayduong.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> points[i].first >> points[i].second;
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
            dist[i][j] = hypot(points[i].first - points[j].first, points[i].second - points[j].second);
    for (int i = 0, u, v; i < m; i++)
        cin >> u >> v,
        has[u][v] = 1,
        has[v][u] = 1;
    for (int i = 1; i <= n; i++) r[i] = 1, p[i] = i;
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
            if (has[i][j])
                e.push_back({0.0, {i, j}});
            else
                e.push_back({dist[i][j], {i, j}});
    sort(e.begin(), e.end());
    for (int i = 0; i < (int)e.size(); i++)
        if (joint(e[i].second.first, e[i].second.second))
            sum += e[i].first;
    cout << fixed << setprecision(2) << sum;
    return 0;
}
