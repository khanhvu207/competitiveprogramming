#include <iostream>
using namespace std;
const int N = 1015;

int n, m, a[N][N], f[4][N][N], dp[N][N];
int b[2 * N][2 * N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      char x;
      cin >> x;
      a[i][j] = (x == '*');
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (i > 1 && j > 1) {
        if ((a[i][j] && a[i - 1][j]) || (a[i][j] && a[i][j - 1])) continue;
        f[0][i][j] = min(f[0][i - 1][j], f[0][i][j - 1]) + 1;
      }
  for (int i = 1; i <= n; ++i)
    for (int j = m; j >= 1; --j)
      if (i > 1 && j < m) {
        if ((a[i][j] && a[i - 1][j]) || (a[i][j] && a[i][j + 1])) continue;
        f[1][i][j] = min(f[1][i - 1][j], f[1][i][j + 1]) + 1;
      }
  for (int i = n; i >= 1; --i)
    for (int j = m; j >= 1; --j)
      if (i < n && j < m) {
        if ((a[i][j] && a[i + 1][j]) || (a[i][j] && a[i][j + 1])) continue;
        f[2][i][j] = min(f[2][i + 1][j], f[2][i][j + 1]) + 1;
      }
  for (int i = n; i >= 1; --i)
    for (int j = 1; j <= m; ++j)
      if (i < n && j > 1) {
        if ((a[i][j] && a[i + 1][j]) || (a[i][j] && a[i][j - 1])) continue;
        f[3][i][j] = min(f[3][i + 1][j], f[3][i][j - 1]) + 1;
      }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = f[0][i][j];
      for (int k = 1; k < 4; ++k)
        dp[i][j] = min(dp[i][j], f[k][i][j]);
      b[1000 + i - j][i + j] = a[i][j];
    }
  for (int i = 1; i <= 1000 + n - 1; ++i)
    for (int j = 2; j <= n + m; ++j)
      b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
  int best = 0, x0, y0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int xl = (1000 + i - j) - dp[i][j];
      int yl = (i + j) - dp[i][j];
      int xr = (1000 + i - j) + dp[i][j];
      int yr = (i + j) + dp[i][j];
      int sum = b[xr][yr] - b[xl - 1][yr] - b[xr][yl - 1] + b[xl - 1][yl - 1];
      if (sum > best) {
        best = sum;
        x0 = i;
        y0 = j;
      }
    }
  cout << best << ' ' << x0 << ' ' << y0 << ' ' << dp[x0][y0];
}
