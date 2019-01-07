#include <bits/stdc++.h>
using namespace std;
const int N = 1015;
const int inf = 1e9;

struct node {
  int u, steps, c;
  node(int uu, int stepss, int cc) {
    this -> u = uu;
    this -> steps = stepss;
    this -> c = cc;
  }
  bool operator < (const node &r) const {
    return c > r.c;
  }
};
priority_queue<node> heap;
int n, cost[N], f[N][555];
bool vis[N][555];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  freopen("loco.inp", "r", stdin);
  freopen("loco.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> cost[i];
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= 500; ++j)
      f[i][j] = inf;
  f[1][0] = 0;
  heap.push(node(1, 0, f[1][0]));
  while (!heap.empty()) {
    int u = heap.top().u;
    int st = heap.top().steps;
    int C = heap.top().c;
    heap.pop();
    if (C > f[u][st])
      continue;
    vis[u][st] = true;
    if (!vis[u + st + 1][st + 1] && C + cost[u + st + 1] < f[u + st + 1][st + 1]) {
      f[u + st + 1][st + 1] = C + cost[u + st + 1];
      heap.push(node(u + st + 1, st + 1, f[u + st + 1][st + 1]));
    }
    if (u - st > 0 && !vis[u - st][st] && C + cost[u - st] < f[u - st][st]) {
      f[u - st][st] = C + cost[u - st];
      heap.push(node(u - st, st, f[u - st][st]));
    }
  }
  int res = inf;
  for (int j = 0; j <= 500; ++j)
    res = min(res, f[n][j]);
  cout << res;
}
