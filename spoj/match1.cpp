#include <bits/stdc++.h>

using namespace std;

const int MAXN = 115 * 2;

int n, m, vis[MAXN], match[MAXN];
vector<int> A[MAXN];

int augmenting(int u) {
  if (vis[u]) {
    return 0;
  }
  vis[u] = true;
  for (auto v : A[u]) {
    if (match[v] == -1 || augmenting(match[v])) {
      match[v] = u;
      return 1;
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  int u, v;
  while (cin >> u >> v) {
    A[u].push_back(v + n);
  }
  int mcbm = 0;
  memset(match, -1, sizeof match);
  for (int i = 1; i <= n; i++) {
    memset(vis, false, sizeof vis);
    mcbm += augmenting(i);
  } 
  cout << mcbm << '\n';
  for (int i = n + 1; i <= n + m; i++) {
    if (match[i] != -1) {
      cout << match[i] << ' ' << i - n << '\n';
    }
  }
  return 0;
}