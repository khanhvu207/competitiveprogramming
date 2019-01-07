#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int N = 1015;
const long long inf = 1e16;

int n, m;
bool vis[N];
vector<int> g[N];
long long L[N][N], d[N];
priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > heap;

void gacongnghiep_2() {
  for (int k = 1; k <= n; ++k)
    for (int u = 1; u <= n; ++u)
      for (int v = 1; v <= n; ++v)
        L[u][v] = min(L[u][v], L[u][k] + L[k][v]);
  for (int i = 1; i <= n; ++i) {
    if (L[i][i] == inf)
      cout << -1 << '\n';
    else
      cout << L[i][i] << '\n';
  }
}

long long Dijkstra(int s) {
  while (!heap.empty())
    heap.pop();
  for (int i = 1; i <= n; ++i)
    d[i] = inf, vis[i] = false;
  heap.push({d[s], s});
  while (!heap.empty()) {
    int u = heap.top().second;
    long long cost = heap.top().first;
    heap.pop();
    if (cost > d[u])
      continue;
    if (u == s) {
      if (d[u] != inf)
        return d[u];
      else
        cost = 0;
    } else
      vis[u] = true;
    for (int i = 0; i < (int)g[u].size(); ++i)
      if (!vis[g[u][i]] && cost + L[u][g[u][i]] < d[g[u][i]]) {
        d[g[u][i]] = cost + L[u][g[u][i]];
        heap.push({d[g[u][i]], g[u][i]});
      }
  }
  return -1;
}

void gacongnghiep_f() {
  for (int vertex = 1; vertex <= n; ++vertex)
    cout << Dijkstra(vertex) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
      g[i].clear();
      for (int j = 1; j <= n; ++j)
        L[i][j] = inf;
    }
    for (int i = 0, u, v, len; i < m; ++i) {
      cin >> u >> v >> len;
      g[u].push_back(v);
      L[u][v] = len;
    }
    if (n <= 100)
      gacongnghiep_2();
    else
      gacongnghiep_f();
  }
}
