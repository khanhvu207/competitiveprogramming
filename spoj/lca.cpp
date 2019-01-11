#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;
#define prev prevv
const int N = 10015;

int n, h[N], p[25][N];
vector<int> g[N];

void DFS(int u, int prev) {
  for (int v : g[u])
    if (v != prev) {
      h[v] = h[u] + 1;
      p[0][v] = u;
      DFS(v, u);
    }
}

int LCA(int u, int v) {
  if (h[u] < h[v])
    swap(u, v);
  for (int i = log2(h[u]) + 1; i >= 0; --i)
    if (p[i][u] != -1 && h[p[i][u]] >= h[v])
      u = p[i][u];
  if (u == v)
    return u;
  for (int i = log2(h[u]) + 1; i >= 0; --i)
    if (p[i][u] != p[i][v])
      u = p[i][u], v = p[i][v];
  return p[0][u];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int q;
  cin >> q;
  for (int tc = 1; tc <= q; ++tc) {
    cin >> n;
    for (int i = 1; i <= n; ++i)
      g[i].clear();
    for (int i = 1; i <= n; ++i) {
      int m;
      cin >> m;
      for (int j = 0, x; j < m; ++j) {
        cin >> x;
        g[i].push_back(x);
        g[x].push_back(i);
      }
    }
    h[1] = 0;
    memset(p, -1, sizeof p);
    DFS(1, -1);
    for (int u = 1; u <= n; ++u)
      for (int i = 1; (1 << i) <= n; ++i)
        if (p[i - 1][u] != -1)
          p[i][u] = p[i - 1][p[i - 1][u]];
    int query;
    cin >> query;
    cout << "Case " << tc << ":\n";
    while (query--) {
      int u, v;
      cin >> u >> v;
      cout << LCA(u, v) << '\n';
    }
  }
}
