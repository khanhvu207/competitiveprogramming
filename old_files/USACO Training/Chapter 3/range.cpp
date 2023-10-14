/*
ID: khanhvu2
LANG: C++14
TASK: range
*/
#include <bits/stdc++.h>
using namespace std;

int n, field[252][252], cnt[252];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("range.in", "r", stdin);
  freopen("range.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char c; cin >> c;
      field[i][j] = c - '0' + field[i - 1][j] + field[i][j - 1] - field[i - 1][j - 1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = 2; k <= n; ++k) {
        if (i - k < 0 || j - k < 0) continue;
        int count = field[i][j] - field[i - k][j] - field[i][j - k] + field[i - k][j - k];
        cnt[k] += count == k * k;
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (!cnt[i]) continue;
    cout << i << ' ' << cnt[i] << '\n';
  }
  return 0;
}