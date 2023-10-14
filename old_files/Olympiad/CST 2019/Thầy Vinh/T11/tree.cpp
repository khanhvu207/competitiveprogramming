#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 100015;
const int inf = 1e9;

int n, res;
int h[N], f[N];
vector<int> g[N];

void DFS1(int u, int p)
{
    int id;
    h[u] = f[u] = 0;
    for (int v : g[u])
        if (v != p) {
            DFS1(v, u);
            if (h[u] < h[v]) {
                h[u] = h[v];
                id = v;
            }
        }
    for (int v : g[u])
        if (v != p && v != id)
            f[u] = max(f[u], h[v]);
    ++h[u];
    ++f[u];
}

void DFS2(int u, int p, int otherh)
{
    res = min(res, max(otherh, h[u]));
    for (int v : g[u])
        if (v != p) {
        int t = (h[v] + 1 == h[u] ? f[u] : h[u]);
        DFS2(v, u, max(otherh, t) + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("tree.inp", "r", stdin);
    freopen("tree.out", "w", stdout);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            g[i].clear();
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        DFS1(1, -1);
        res = inf;
        DFS2(1, -1, 1);
        cout << res - 1 << '\n';
    }
}
