#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
const int N = 65;

int n, k;
string t;
long long f[N][N][N], res = 0;

long long dp(int i, int open, int lv) {
  if (f[i][open][lv] != -1ll)
    return f[i][open][lv];
  if (i == n)
    return (lv == k && open == 0) * 1ll;
  f[i][open][lv] = dp(i + 1, open + 1, max(lv, open + 1));
  if (open > 0)
    f[i][open][lv] += dp(i + 1, open - 1, max(lv, open - 1));
  return f[i][open][lv];
}

void trace(int i, int open, int lv) {
  if (i == n) {
    cout << res + 1;
    exit(0);
  }
  if (t[i] == '(')
    trace(i + 1, open + 1, max(lv, open + 1));
  else {
    res += dp(i + 1, open + 1, max(lv, open + 1));
    trace(i + 1, open - 1, max(lv, open - 1));
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  memset(f, -1ll, sizeof f);
  cout << dp(0, 0, 0) << '\n';
  cin >> t;
  trace(0, 0, 0);
}
