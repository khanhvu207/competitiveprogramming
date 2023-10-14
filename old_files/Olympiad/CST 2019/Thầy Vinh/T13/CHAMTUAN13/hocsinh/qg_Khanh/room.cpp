#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int N = 300015;

int n, r[N], p[N];
set<pair<int, int> > e;
map<pair<int, int>, int> mp;

bool joint(int u, int v) {
  while (p[u] != u)
    p[u] = p[p[u]], u = p[u];
  while (p[v] != v)
    p[v] = p[p[v]], v = p[v];
  if (u == v) return false;
  if (r[u] > r[v])
    r[u] += r[v], p[v] = u;
  else
    r[v] += r[u], p[u] = v;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  freopen("room.inp", "r", stdin);
  freopen("room.out", "w", stdout);
  cin >> n;
  int x = 0, y = 0;
  mp[{x, y}] = mp.size();
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    int t = c - 48;
    for (int i = 0; i < 2; ++i) {
      int rx = x + dx[t];
      int ry = y + dy[t];
      if (!mp.count({rx, ry}))
        mp[{rx, ry}] = mp.size();
      int a = mp[{x, y}];
      int b = mp[{rx, ry}];
      if (a > b)
        swap(a, b);
      e.insert(make_pair(a, b));
      x = rx;
      y = ry;
    }
  }
  int m = mp.size();
  for (int i = 1; i <= m; ++i)
    r[i] = 1, p[i] = i;
  int cnt = 0;
  for (set<pair<int, int> >::iterator it = e.begin(); it != e.end(); ++it)
    if (joint(it -> first, it -> second))
      ++cnt;
  cout << (int)e.size() - cnt;
}
