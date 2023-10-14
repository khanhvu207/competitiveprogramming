#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1015;
const long long inf = 1e18;

int n, m;
long long c[N][N], f[N][N][3];

long long dp(int i, int a, int isA) {
  if (f[i][a][isA] != -1)
    return f[i][a][isA];
  if (i > n + m)
    return 0ll;
  f[i][a][isA] = inf;
  int b = i - 1 - a;
  if (a + 1 <= n)
    f[i][a][isA] = min(f[i][a][isA], (isA == 1 ? 0 : c[a + 1][b]) + dp(i + 1, a + 1, 1));
  if (b + 1 <= m)
    f[i][a][isA] = min(f[i][a][isA], (isA == 0 ? 0 : c[a][b + 1]) + dp(i + 1, a, 0));
  return f[i][a][isA];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        cin >> c[i][j];
    for (int i = 0; i <= n + m + 1; ++i)
      for (int j = 0; j <= n; ++j)
        for (int k = 0; k < 3; ++k)
          f[i][j][k] = -1;
    cout << dp(1, 0, 2) << '\n';
  }
}
