#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int N = 30015;

int n, m, low[N], num[N], timer, res = 1, BCC, id[N];
vector<int> g[N];
stack<int> s;

void DFS(int u){
   num[u] = low[u] = ++timer;
   for (int v : g[u])
    if (num[v] > 0)
      low[u] = min(low[u], num[v]);
    else {
      s.push(u);
      DFS(v);
      low[u] = min(low[u], low[v]);
      if (low[v] >= num[u]) {
        int cnt = 0, k;
        ++BCC;
        do {
          k = s.top();
          s.pop();
          if (id[k] < BCC) {
            id[k] = BCC;
            ++cnt;
          }
        } while (u != k);
        res = max(res, cnt);
      }
    }
  s.push(u);
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
    if (!num[i]) DFS(i);
  cout << res;
}
