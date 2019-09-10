/*
 ID: khanhvu2
 LANG: C++11
 TASK: nocows
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MOD = 9901;
int n, k, f[222][111];

int solve(int total, int lv) {
  if (lv > k) return 0;
  if (total == 1) return 1;
  int &res = f[total][lv];
  if (res != -1) return res;
  res = 0;
  --total;
  for (int i = 1; i < total; ++i) {
    res += solve(i, lv + 1) * solve(total - i, lv + 1);
    res %= MOD;
  }
  return res;
}

int main() 
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("nocows.in", "r", stdin);
  freopen("nocows.out", "w", stdout);
  cin >> n >> k;
  memset(f, -1, sizeof f);
  int ans = solve(n, 1);
  --k;
  memset(f, -1, sizeof f);
  ans -= solve(n, 1) % MOD;
  ans = (ans + MOD) % MOD;
  cout << ans << '\n';
}