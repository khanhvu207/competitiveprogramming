#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m, nxt[100015], p[100015];
bool vst[100015];
vector<int> topo;

void dfs (int u)
{
    vst[u] = true;
    if (nxt[u] != -1 && !vst[nxt[u]]) dfs(nxt[u]);
    topo.push_back(u);
}

void knock (int u)
{
    vst[u] = true;
    if (nxt[u] != -1 && !vst[nxt[u]]) knock(nxt[u]);
}

int main()
{
    freopen("11504.inp", "r", stdin);
    freopen("11504.out", "w", stdout);

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(vst, false, sizeof vst);
        memset(p, 0, sizeof p);
        memset(nxt, -1, sizeof nxt);
        for (int i = 0, u, v; i < m; ++i)
            cin >> u >> v,
            nxt[u] = v,
            ++p[v];
        int cnt = 0;
        for (int u = 1; u <= n; ++u)
            if (p[u] < 1 && !vst[u]) dfs(u), ++cnt;
        for (int u = 1; u <= n; ++u)
            if (!vst[u]) knock(u);
//        reverse(topo.begin(), topo.end());
//        int cnt = 0;
//        for (int u = 1; u <= n; ++u) vst[u] = false;
//        for (int u = 1; u <= n; ++u)
//            if (!vst[u]) knock(u), ++cnt;
        cout << cnt << '\n';
    }
}
