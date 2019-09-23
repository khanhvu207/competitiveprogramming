/*
ID: khanhvu2
LANG: C++14
TASK: fracdec
*/
#include <bits/stdc++.h>
using namespace std;

string ans = "";
int n, d, aux;
bool chk;
unordered_map<int, int> vis;

int main() {
  freopen("fracdec.in", "r", stdin);
  freopen("fracdec.out", "w", stdout);
  cin >> n >> d;
  int dec = n / d;
  n %= d;

  while (n) {
    n *= 10;
    string tmp = "";
    if (vis.count(n)) {
        chk = true;
        break;
      }
    vis[n] = (int)ans.size();
    tmp = tmp + (char)(n / d + '0');
    ans += tmp;
    n %= d;
  }

  if (chk) {
    ans.insert(vis[n], "(");
    ans += ')';
  }

  if (ans == "") {
    ans += '0';
  }

  ans = '.' + ans;

  if (!dec) {
    ans = '0' + ans;
  }
  else while (dec) {
    ans = (char)(dec % 10 + '0') + ans;
    dec /= 10;
  }

  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i];
    if ((i + 1) % 76 == 0 && i + 1 != (int)ans.size()) {
      cout << '\n';
    }

  }
  cout << '\n';
}