#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define prev prevvvv
const int N = 2015;

int n, h[N], p[20][N];
double t[N], d[N], V[N], L[N][N];
vector<int> g[N];

void DFS(int u, int prev) {
    for (int v : g[u])
        if (v != prev) {
            d[v] = d[u] + L[u][v];
            h[v] = h[u] + 1;
            p[0][v] = u;
            DFS(v, u);
        }
}

int LCA (int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    for (int i = 15; i >= 0; --i)
        if (h[p[i][u]] >= h[v]) u = p[i][u];
    if (u == v)
        return u;
    for (int i = 15; i >= 0; --i)
        if (p[i][u] != p[i][v])
            u = p[i][u],
            v = p[i][v];
    return p[0][u];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("xengua.inp", "r", stdin);
    freopen("xengua.out", "w", stdout);
    cout << fixed;
    cout.precision(4);
    cin >> n;
    for (int u = 1; u <= n; ++u)
        cin >> t[u] >> V[u];
    for (int i = 0, u, v, len; i < n - 1; ++i) {
        cin >> u >> v >> len;
        g[u].push_back(v);
        g[v].push_back(u);
        L[u][v] = L[v][u] = len;
    }
    h[1] = 0;
    d[1] = 0;
    p[0][1] = -1;
    DFS(1, -1);
    double res = 0.0;
    for (int u = 1; u <= n; ++u)
        for (int i = 1; (1 << i) <= n; ++i)
            if (p[0][u] != -1)
                p[i][u] = p[i - 1][p[i - 1][u]];
    for (int u = 2; u <= n; ++u) {
        double best = d[u] / V[u] / 1.0 + t[u];
        for (int v = 1; v <= n; ++v) {
            int x = LCA(u, v);
            double cost = (d[u] - d[x] + d[v] - d[x]) / V[u] / 1.0 + d[v] / V[v] / 1.0 + t[u] + t[v];
            best = fmin(best, cost);
        }
        res = fmax(res, best);
    }
    cout << res;
}
