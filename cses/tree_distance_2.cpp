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

  vector<ll> d(n, 0);
  vector<ll> s(n, 0);
  function<void(int, int)> precomp = [&](int u, int p) {
    s[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        precomp(v, u);
        d[u] += d[v] + s[v];
        s[u] += s[v];
      }
    }
  };
  precomp(0, -1);

  vector<ll> res(n, 0);
  function<void(int, int, ll, ll)> dp = [&](int u, int p, ll dd, ll ss) {
    res[u] = dd + d[u];
    
    for (int v : g[u]) {
      if (v != p) {
        ll cur_d = d[u] - d[v] - s[v];
        ll cur_s = s[u] - s[v];
        dp(v, u, dd + ss + cur_d + cur_s, ss + cur_s); 
      }
    }
  };
  dp(0, -1, 0, 0);

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
