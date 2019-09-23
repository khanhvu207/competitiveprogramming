/*
ID: khanhvu2
LANG: C++14
TASK: concom
*/
#include <bits/stdc++.h>
using namespace std;

int n, c[101][101];
bool vst[101];
vector<pair<int, int>> g[101];

void dfs(int u, int t, int pC) {
  c[u][t]+=pC;
  if (c[u][t]<=50) return;
  vst[t]=true;
  for (pair<int, int> p : g[t])
    if (!vst[p.first])
      dfs(u, p.first, p.second);
}

int main() {
  freopen("concom.in", "r", stdin);
  freopen("concom.out", "w", stdout);
  cin>>n;
  
  for (int i=0, u, v, p; i<n; ++i) {
    cin>>u>>v>>p;
    g[u].push_back({v, p});
  }

  for (int i=1; i<=100; ++i) {
    memset(vst, false, sizeof vst);
    for (pair<int, int> p : g[i])
      dfs(i, p.first, p.second);
  }

  for (int u=1; u<=100; ++u) {
    for (int v=1; v<=100; ++v) {
      if (c[u][v]<=50 || u==v) continue;
      cout<<u<<' '<<v<<'\n';
    }
  }
  return 0;
}