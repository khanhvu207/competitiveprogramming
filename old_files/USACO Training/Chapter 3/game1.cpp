/*
ID: khanhvu2
LANG: C++14
TASK: game1
*/
#include <bits/stdc++.h>
using namespace std;

int n, a[100];
pair<int, int> f[2][100][100];

pair<int, int> dp(int player, int l, int r) {
  if (f[player][l][r] != pair<int, int>(-1, -1)) return f[player][l][r];
  if (l == r) {
    if (!player) {
      return pair<int, int>(a[l], 0);
    }
    else {
      return pair<int, int>(0, a[l]);
    }
  }
  pair<int, int> res;
  pair<int, int> option_l = dp(player ^ 1, l + 1, r);
  if (!player) option_l.first += a[l];
    else option_l.second += a[l];
  pair<int, int> option_r = dp(player ^ 1, l, r - 1);
  if (!player) option_r.first += a[r];
    else option_r.second += a[r];
  if (!player) {
    if (option_l.first > option_r.first) res = option_l;
      else res = option_r;
  }
  else {
    if (option_l.second > option_r.second) res = option_l;
      else res = option_r;
  }
  f[player][l][r] = res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("game1.in", "r", stdin);
  freopen("game1.out", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      f[0][i][j] = {-1, -1};
      f[1][i][j] = {-1, -1};
    }
  }
  pair<int, int> res = dp(0, 0, n - 1);
  cout << res.first << ' ' << res.second << '\n';
  return 0;
}

