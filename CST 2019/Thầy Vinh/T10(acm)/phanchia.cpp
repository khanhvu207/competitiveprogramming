#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1000;

int n, m;
long long powx[N], sum[N * 2], cost[N * 2][N * 2];
int r[N * 2], px[N * 2], h[N * 2], p[25][N * 2];
bool vis[N * 2];

vector<int> tmp;
vector<int> g[N];
map<long long, int> mp;
vector<pair<long long, pair<int, int> > > elist, leftover;

bool joint(int u, int v)
{
    while (u != px[u]) px[u] = px[px[u]], u = px[u];
    while (v != px[v]) px[v] = px[px[v]], v = px[v];
    if (u == v) return false;
    if (r[u] > r[v])
        r[u] += r[v], px[v] = u;
    else
        r[v] += r[u], px[u] = v;
    return true;
}

void DFS(int u, int pv)
{
    vis[u] = true;
    for (int i = 0; i < (int)g[u].size(); ++i)
    {
        int v = g[u][i];
        if (v == pv) continue;
        h[v] = h[u] + 1;
        sum[v] = sum[u] + cost[u][v];
        p[0][v] = u;
        DFS(v, u);
    }
}

int LCA (int u, int v)
{
    if (h[u] < h[v]) swap(u, v);
    for (int i = log2(h[u]) + 1; i >= 0; --i)
        if (h[p[i][u]] >= h[v]) u = p[i][u];
    if (u == v) return u;
    for (int i = log2(h[u]) + 1; i >= 0; --i)
        if (p[i][u] != p[i][v])
            u = p[i][u],
            v = p[i][v];
    return p[0][u];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("phanchia.inp", "r", stdin);
    freopen("phanchia.out", "w", stdout);

    powx[0] = 1ll;
    for (int i = 1; i <= 105; ++i)
        powx[i] = (powx[i - 1] * 105) % mod;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int index, x, y;
        long long len;
        cin >> index >> len >> x >> y;
        int hashU = 0, hashV = 0, u, v;

        tmp.clear();
        tmp.push_back(index);
        for (int j = 0, k; j < x; ++j)
        {
            cin >> k;
            tmp.push_back(k);
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < (int)tmp.size(); ++i)
            hashU = ((tmp[i] * powx[i]) % mod + hashU) % mod;
        if (!mp.count(hashU))
            mp[hashU] = mp.size();

        tmp.clear();
        tmp.push_back(index);
        for (int j = 0, k; j < y; ++j)
        {
            cin >> k;
            tmp.push_back(k);
        }
        sort(tmp.begin(), tmp.end());
         for (int i = 0; i < (int)tmp.size(); ++i)
            hashV = ((tmp[i] * powx[i]) % mod + hashV) % mod;
        if (!mp.count(hashV))
            mp[hashV] = mp.size();

        u = mp[hashU], v = mp[hashV];
        elist.push_back({len, {u, v}});
    }

    sort(elist.begin(), elist.end());
    m = mp.size();
    for (int u = 1; u <= m; ++u)
        r[u] = 1, px[u] = u;

    int root;
    for (int i = 0; i < (int)elist.size(); ++i)
    {
        int u = elist[i].second.first;
        int v = elist[i].second.second;
        if (joint(u, v))
        {
            root = u;
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u][v] = cost[v][u] = elist[i].first;
        } else leftover.push_back(elist[i]);
    }

    long long res = 1e18;

    for (int X = 1; X <= m; ++X)
        if (!vis[X])
        {
            memset(h, 0, sizeof h);
            memset(sum, 0, sizeof sum);

            h[X] = 0;
            sum[X] = 0;
            DFS(X, -1);

            for (int u = 1; u <= m; ++u)
                for (int i = 1; (1 << i) <= m; ++i)
                    p[i][u] = p[i - 1][p[i - 1][u]];

            for (int i = 0; i < (int)leftover.size(); ++i)
                {
                    int u = leftover[i].second.first;
                    int v = leftover[i].second.second;
                    if (sum[v] < 1 && sum[u] < 1) continue;
                    int x = LCA(u, v);
                    res = min(res, sum[u] + sum[v] - 2ll * sum[x] + leftover[i].first);
                }
        }
    cout << res;
}
