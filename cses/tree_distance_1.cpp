#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
// const ll MOD = 1000000007;
const ll MOD = 998244353;
const bool is_multitest = false;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> h(n, 0);
  function<void(int, int)> precomp = [&](int u, int p) {
    for (int v : g[u]) {
      if (v != p) {
        precomp(v, u);
        h[u] = max(h[u], 1 + h[v]);
      }
    }
  };
  precomp(0, -1);

  vector<int> res(n, 0);
  function<void(int, int, int)> dp = [&](int u, int p, int c) {
    res[u] = max(c, h[u]);

    int m = (int)g[u].size();
    vector<int> pf(m, 0);
    vector<int> sf(m, 0);
    for (int i = 0; i < m; ++i) {
      pf[i] = i > 0 ? pf[i-1] : 0;
      if (g[u][i] != p) {
        pf[i] = max(pf[i], h[g[u][i]]);
      }
    }
    for (int i = m-1; i >= 0; --i) {
      sf[i] = (i + 1 < m) ? sf[i+1] : 0;
      if (g[u][i] != p) {
        sf[i] = max(sf[i], h[g[u][i]]);
      }
    }
    for (int i = 0; i < m; ++i) {
      int v = g[u][i];
      if (v != p) {
        int other = 0;
        if (i > 0) other = max(other, pf[i-1]+1);
        if (i + 1 < m) other = max(other, sf[i+1]+1);
        dp(v, u, max(c, other) + 1);
      }
    }
  };
  dp(0, -1, 0);

  for (int i = 0; i < n; ++i) {
    cout << res[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  if (is_multitest) cin >> t;
  while (t--) solve();
  return 0;
}
