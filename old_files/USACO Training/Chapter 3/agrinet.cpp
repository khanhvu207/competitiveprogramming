/*
ID: khanhvu2
LANG: C++14
TASK: agrinet
*/
#include <bits/stdc++.h>
using namespace std;

int n, mst, c[101][101];
bool vst[101];

int main() {
  freopen("agrinet.in", "r", stdin);
  freopen("agrinet.out", "w", stdout);
  cin >> n;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> c[i][j];

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, 0});

  while (!q.empty()) {
    int len = q.top().first;
    int u = q.top().second;
    q.pop();
    if (vst[u]) continue;
    vst[u] = true;
    mst += len;
    for (int i = 0; i < n; ++i)
      if (i != u && !vst[i])
        q.push({c[u][i], i});
  }

  cout << mst << '\n';
  return 0;
}
