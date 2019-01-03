#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 10015;

int n;
long long f[N], child[N];
long long res = 0;
vector<int> g[N];

void DFS1(int u, int p) {
    f[u] = 0;
    child[u] = 0;
    for (int v : g[u])
        if (v != p) {
            DFS1(v, u);
            f[u] += f[v] + child[v];
            child[u] += child[v];
        }
    ++child[u];
}

void DFS2(int u, int p, int other, int c) {
    res += f[u] + other;
    for (int v : g[u])
        if (v != p) {
            int tmp_f = f[u] - f[v] - child[v];
            int tmp_c = c + child[u] - child[v];
            DFS2(v, u, (other + tmp_f) + tmp_c, tmp_c);
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("huunghi.inp", "r", stdin);
    freopen("huunghi.out", "w", stdout);
    cin >> n;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    DFS1(1, -1);
    DFS2(1, -1, 0, 0);
    cout << res / 2;
}
