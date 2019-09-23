/*
ID: khanhvu2
LANG: C++14
TASK: comehome
*/
#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;
int n, d[200];
bool vst[200];
vector<pair<int, int>> g[200];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("comehome.in", "r", stdin);
  freopen("comehome.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char u, v; int c;
    cin >> u >> v >> c;
    g[u].push_back({v, c});
    g[v].push_back({u, c});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  for (char c = 'A'; c <= 'Z'; ++c) {
    d[c] = inf;
    d[c + ('a' - 'A')] = inf;
  }
  d['Z'] = 0;
  q.push({d['Z'], 'Z'});
  while (!q.empty()) {
    int u = q.top().second;
    int dist = q.top().first;
    q.pop();
    if (dist > d[u]) continue;
    vst[u] = true;
    for (pair<int, int> v : g[u]) 
      if (!vst[v.first] && v.second + dist < d[v.first]) {
        d[v.first] = v.second + dist;
        q.push({d[v.first], v.first});
      }
  }
  int best = inf;
  char ans;
  for (char c = 'A'; c < 'Z'; ++c)
    if (d[c] < best) {
      best = d[c];
      ans = c;
    }
  cout << ans << ' ' << best << '\n';
  return 0;
}