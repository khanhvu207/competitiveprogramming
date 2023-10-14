#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;
const int N = 100015;
const int K = 25;
const int inf = 2e9;

int n, h[N], p[K][N], rmin[K][N], rmax[K][N];
vector<pair<int, int> > g[N];

void DFS(int u) {
  for (pair<int, int> x : g[u]) {
    int v = x.first;
    int L = x.second;
    if (v == p[0][u])
      continue;
    h[v] = h[u] + 1;
    rmin[0][v] = L;
    rmax[0][v] = L;
    p[0][v] = u;
    DFS(v);
  }
}

int LCA(int u, int v) {
  if (h[u] < h[v])
    swap(u, v);
  int k = log2(h[u]);
  for (int i = k; i >= 0; --i)
    if (p[i][u] != -1 && h[p[i][u]] >= h[v])
      u = p[i][u];
  if (u == v)
    return u;
  for (int i = k; i >= 0; --i)
    if (p[i][u] != p[i][v])
      u = p[i][u], v = p[i][v];
  return p[0][u];
}

int getmin(int u, int lca) {
  if (u == lca)
    return inf;
  int res = inf;
  int k = log2(h[u]);
  for (int i = k; i >= 0; --i)
    if (h[p[i][u]] >= h[lca]) {
      res = min(res, rmin[i][u]);
      u = p[i][u];
    }
  return res;
}

int getmax(int u, int lca) {
  if (u == lca)
    return 0;
  int res = 0;
  int k = log2(h[u]);
  for (int i = k; i >= 0; --i)
    if (h[p[i][u]] >= h[lca]) {
      res = max(res, rmax[i][u]);
      u = p[i][u];
    }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0, u, v, c; i < n - 1; ++i) {
    cin >> u >> v >> c;
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  h[1] = 1;
  memset(p, -1, sizeof p);
  DFS(1);
  for (int i = 1; (1 << i) <= n; ++i)
    for (int u = 1; u <= n; ++u)
      if (p[i - 1][u] != -1) {
        p[i][u] = p[i - 1][p[i - 1][u]];
        rmin[i][u] = min(rmin[i - 1][u], rmin[i - 1][p[i - 1][u]]);
        rmax[i][u] = max(rmax[i - 1][u], rmax[i - 1][p[i - 1][u]]);
      }
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    int x = LCA(u, v);
    cout << min(getmin(u, x), getmin(v, x)) << ' ' << max(getmax(u, x), getmax(v, x)) << '\n';
  }
}
