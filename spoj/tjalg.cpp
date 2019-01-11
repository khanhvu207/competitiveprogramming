#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N = 10015;
const int inf = 1e9;

int n, m, low[N], num[N], timer, cnt;
vector<int> g[N];
stack<int> s;

void DFS(int u) {
  num[u] = low[u] = ++timer;
  s.push(u);
  for (int v : g[u]) {
    if (num[v] > 0)
      low[u] = min(low[u], num[v]);
    else {
      DFS(v);
      low[u] = min(low[u], low[v]);
    }
  }
  if (num[u] == low[u]) {
    ++cnt;
    while (true) {
      int v = s.top();
      s.pop();
      num[v] = low[v] = inf;
      if (v == u)
        break;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i)
    if (!num[i])
      DFS(i);
  cout << cnt;
}
