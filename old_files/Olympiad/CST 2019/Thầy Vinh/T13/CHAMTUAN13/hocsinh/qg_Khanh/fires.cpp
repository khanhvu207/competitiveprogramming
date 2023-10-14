#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int R = 1000015;
const int N = 300015;

int n, bit[R * 3];
long long a[4][N], val[R * 3];

void update(int x, int val) {
  for (; x <= 3000000; x = (x | (x + 1)))
    bit[x] += val;
}

int get(int x) {
  int cnt = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1)
    cnt += bit[x];
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  freopen("fires.inp", "r", stdin);
  freopen("fires.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> a[i][j];
  for (int i = 1; i <= n; ++i) {
    val[1] += 1;
    val[a[1][i] + 1] -= 1;
  }
  for (int i = 1; i <= n; ++i) {
    val[a[1][i] + 1] += 2;
    val[a[1][i] + a[2][i] + 1] -= 2;
  }
  for (int i = 1; i <= n; ++i) {
    val[a[1][i] + a[2][i] + 1] += 5;
    val[a[1][i] + a[2][i] + a[3][i] + 1] -= 5;
  }
  for (int i = 2; i <= 1000000 * 3; ++i)
    val[i] += val[i - 1];
  int q;
  cin >> q;
  for (int i = 1; i <= 3000000; ++i)
    update(i, 1);
  while (q--) {
    int x;
    cin >> x;
    int l = 1;
    int r = 3000000;
    int k = 0;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (get(m) >= x)
        r = m - 1;
      else
        l = m + 1;
    }
    cout << val[l] << '\n';
    update(l, -1);
  }
}
