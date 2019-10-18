/*
ID: khanhvu2
LANG: C++14
TASK: inflate
*/
#include <bits/stdc++.h>
using namespace std;

int m, n, p[10001], t[10001], f[10001];

int main() {
  freopen("inflate.in", "r", stdin);
  freopen("inflate.out", "w", stdout);

  cin >> m >> n;

  for (int i = 0; i < n; ++i) {
    cin >> p[i] >> t[i];
  }

  for (int i = 0; i <= m; ++i)
    for (int j = 0; j < n; ++j)
      if (i >= t[j] && f[i - t[j]] + p[j] > f[i])
        f[i] = f[i - t[j]] + p[j];

  cout << f[m] << '\n';
  return 0;
}
