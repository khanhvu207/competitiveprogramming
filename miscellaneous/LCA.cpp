#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const long long mod = 1e9 + 7;
int n, m, q, h[100015], cnt[100015][20], p[100015][20];
bool vst[100015], cycle[100015];
vector<int> g[100015];
long long pow2[100015];

void dfs (int u)
{
    vst[u] = 1;
    for (int v : g[u])
        if (vst[v] && v != p[u][0] && !cycle[v])
        {
            int x = u;
            while (x != v)
            {
                cycle[x] = 1;
                x = p[x][0];
            }
            cycle[v] = 1;
            cnt[v][0] = 1;
        } else if (!vst[v])
            h[v] = h[u] + 1,
            p[v][0] = u,
            dfs(v);
}

int LCA (int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    for (int i = log2(h[u]); i >= 0; --i)
        if (h[p[u][i]] >= h[v]) u = p[u][i];
    if (u == v) return u;
    for (int i = log2(h[u]); i >= 0; --i)
        if (p[u][i] != p[v][i])
            u = p[u][i],
            v = p[v][i];
    return p[u][0];
}

int get (int u, int v)
{
    int res = cnt[v][0];
    for (int i = log2(h[u]); i >= 0; --i)
        if (h[p[u][i]] >= h[v])
            res += cnt[u][i], u = p[u][i];
    return res;
}

long long calc (int u, int v)
{
    int x = LCA(u, v);
    return pow2[get(u, x) + get(v, x) - 2 * cnt[x][0] + cycle[x]] % mod;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("cactus.inp", "r", stdin);
    freopen("cactus.out", "w", stdout);

    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i)
        cin >> u >> v,
        g[u].push_back(v),
        g[v].push_back(u);
    h[1] = 1;
    dfs(1);
    for (int i = 1; (1 << i) <= n; ++i)
        for (int u = 1; u <= n; ++u)
            p[u][i] = p[p[u][i - 1]][i - 1],
            cnt[u][i] = cnt[u][i - 1] + cnt[p[u][i - 1]][i - 1];
    cin >> q;

    pow2[0] = 1;
    for (int i = 1; i <= 100000; ++i) pow2[i] = (pow2[i - 1] * 2) % mod;

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << calc(u, v) << '\n';
    }
}
