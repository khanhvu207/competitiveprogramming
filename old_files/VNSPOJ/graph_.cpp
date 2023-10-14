#include <iostream>
#include <vector>
using namespace std;
const int N = 10015;

int n, m, num[N], low[N], bridge, timer;
bool critical[N];
vector<int> g[N];

void DFS(int u, int p = -1) {
  int child = 0;
  num[u] = low[u] = ++timer;
  for (int v : g[u]) {
    if (v == p)
      continue;
    if (num[v] > 0)
      low[u] = min(low[u], num[v]);
    else {
      DFS(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= num[u] && p != -1)
        critical[u] = true;
      if (low[v] > num[u])
        ++bridge;
      ++child;
    }
  }
  if (p == -1 && child > 1)
    critical[u] = true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i)
    if (!num[i])
      DFS(i);
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    cnt += critical[i];
  cout << cnt << ' ' << bridge << '\n';
}
