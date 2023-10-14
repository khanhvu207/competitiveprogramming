#include <iostream> 
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int main() {
#ifdef THEMIS
	freopen("DANANG.INP", "r", stdin);
	freopen("DANANG.OUT", "w", stdout);
#endif // THEMIS

  ios::sync_with_stdio(false);
  
  int n, m, l; cin >> n >> m >> l;
  vector<vector<pair<int, int>>> adj(n);
  while (m--) {
    int u, v, c; cin >> u >> v >> c; u--; v--;
    adj[u].push_back({c, v});
    adj[v].push_back({c, u});
  }
  for (int u = 0; u < n; u++)
    sort(adj[u].begin(), adj[u].end());
  
  typedef tuple<long long, int, int> elt;
  priority_queue<elt, vector<elt>, greater<elt>> pq;
  pq.push(make_tuple(0, -l, 0));
  long long res = -1;
  while (!pq.empty()) {
    long long dist; int last, u;
    tie(dist, last, u) = pq.top(); pq.pop();
    if (u == n-1) {
      res = dist;
      break;
    }
    while (!adj[u].empty()) {
      int c, v; tie(c, v) = adj[u].back();
      if (c < last + l) break;
      adj[u].pop_back();
      pq.push(make_tuple(dist + c, c, v));
    }
  }
  cout << res << endl;
}
