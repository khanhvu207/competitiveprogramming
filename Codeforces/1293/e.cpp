#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 3005;
int n, par[N][N], subtree[N][N];
ll f[N][N];
vector<int> g[N];

void dfs(int root, int u, int p) {
    subtree[root][u] = 1;
    for (int v : g[u]) 
        if (v != p) {
            par[root][v] = u;
            dfs(root, v, u);
            subtree[root][u] += subtree[root][v];
        }
}

ll dp(int u, int v) {
    if (u == v) return 0;
    ll& res = f[u][v];
    if (res != -1) return res;
    res = subtree[u][v] * subtree[v][u] + max(dp(u, par[u][v]), dp(v, par[v][u]));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) dfs(i, i, -1);
    memset(f, -1, sizeof f); 
    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v) 
            res = max(res, dp(u, v));
    cout << res;
}
