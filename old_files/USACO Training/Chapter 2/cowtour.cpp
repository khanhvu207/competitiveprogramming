/*
ID: khanhvu2 
LANG: C++14
TASK: cowtour
*/
#include <bits/stdc++.h>
using namespace std;

int n, idx;
bool vst[151];
double diameter[151], farthest[151], f[151][151];
vector<int> g[151], cc[151];
pair<double, double> pos[151];

double dist(const pair<double, double> &a, const pair<double, double> &b) {
  double dx = a.first-b.first;
  double dy = a.second-b.second;
  return sqrt(dx*dx+dy*dy);
}

void dfs(int u) {
  vst[u] = true;
  cc[idx].push_back(u);
  for (int v : g[u])
    if (!vst[v]) dfs(v);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("cowtour.in", "r", stdin);
  freopen("cowtour.out", "w", stdout);
  
  cin >> n;
  for (int i = 0; i < n; ++i) {
    double x, y; cin >> x >> y;
    pos[i] = {x, y};
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      char c; cin >> c;
      f[i][j] = i == j ? 0 : 1e9;
      if (c == '1') {
        f[i][j] = dist(pos[i], pos[j]);
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  
  
  for (int k = 0;  k < n; ++k) 
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
      }
  
  for (int i = 0; i < n; ++i) if (!vst[i]) {
    dfs(i);
    for (int u : cc[idx])
      for (int v : cc[idx]) 
        if (u != v) {
          diameter[idx] = max(diameter[idx], f[u][v]);
          farthest[u] = max(farthest[u], f[u][v]);
        }
    ++idx;
  }

  double res = 1e18;

  for (int i = 0; i < idx-1; ++i)
    for (int j = i+1; j < idx; ++j) {
      double D = 1e18;
      for (int u : cc[i])
        for (int v : cc[j]) {
          D = min(D, farthest[u]+farthest[v]+dist(pos[u], pos[v]));
        }
      res = min(res, max(D, max(diameter[i], diameter[j])));
    }
  
  cout << fixed << setprecision(6) << res << '\n';
  return 0;
}