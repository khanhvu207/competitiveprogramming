#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll n, x, pow6[25], f[30][150];

ll dp(int i, int sum) {
  if (f[i][sum] != -1ll)
    return f[i][sum];
  if (i == n)
    return (sum >= x) * 1ll;
  f[i][sum] = 0ll;
  for (int v = 1; v <= 6; ++v)
    f[i][sum] += dp(i + 1, sum + v);
  return f[i][sum];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  freopen("10759.inp", "r", stdin);
  freopen("10759.out", "w", stdout);
  pow6[0] = 1;
  for (int i = 1; i <= 24; ++i)
    pow6[i] = pow6[i - 1] * 6ll;
  while (cin >> n >> x) {
    if (!n && !x)
      return 0;
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= 6 * n; ++j)
        f[i][j] = -1;
    ll denum = dp(0, 0);
    ll GCD = __gcd(denum, pow6[n]);
    denum /= GCD;
    ll p6 = pow6[n] / GCD;
    if (denum % p6 == 0)
      cout << denum / p6 << '\n';
    else
      cout << denum << '/' << p6 << '\n';
  }
}
