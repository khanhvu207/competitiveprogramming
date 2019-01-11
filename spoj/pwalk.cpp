#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;
const int N = 10015;

int n, q, h[N], L[N], p[N];
vector<pair<int, int> > g[N];

void DFS(int u, int par) {
  for (pair<int, int> v : g[u])
    if (v.first != par) {
      h[v.first] = h[u] + 1;
      L[v.first] = v.second;
      p[v.first] = u;
      DFS(v.first, u);
    }
}

int path(int u, int v) {
  int res = 0;
  while (h[u] > h[v])
    res += L[u], u = p[u];
  while (h[v] > h[u])
    res += L[v], v = p[v];
  while (u != v)
    res += L[u] + L[v], u = p[u], v = p[v];
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> q;
  for (int i = 0, u, v; i < n - 1; ++i) {
    long long c;
    cin >> u >> v >> c;
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  memset(p, -1, sizeof p);
  h[1] = 0;
  DFS(1, 1);
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << path(u, v) << '\n';
  }
}
