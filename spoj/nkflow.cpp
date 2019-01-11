#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1015;
const int inf = 1e9;

int n, m, s, t, p[N];
long long r[N][N], f;
vector<int> g[N];

void augment(int u, long long k) {
  if (u == s) {
    f = k;
    return;
  } else if (p[u] != -1) {
    augment(p[u], min(k, r[p[u]][u]));
    r[u][p[u]] += f;
    r[p[u]][u] -= f;
  }
}

int maxflow() {
  long long maxflow = 0;
  while (true) {
    f = 0;
    for (int i = 1; i <= n; ++i)
      p[i] = -1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == t)
        break;
      for (int v : g[u])
        if (r[u][v] > 0 && p[v] == -1) {
          p[v] = u;
          q.push(v);
        }
    }
    augment(t, inf);
    if (f == 0)
      break;
    maxflow += f;
  }
  return maxflow;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m >> s >> t;
  for (int i = 0, u, v, c; i < m; ++i) {
    cin >> u >> v >> c;
    r[u][v] += c;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << maxflow();
}
