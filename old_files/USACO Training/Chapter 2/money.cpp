/*
 ID: khanhvu2
 LANG: C++11
 TASK: money
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
int v, n;
ll f[10015];
vector<int> coin;

int main() {
  freopen("money.in", "r", stdin);
  freopen("money.out", "w", stdout);
  cin >> v >> n;
  for (int i = 0; i < v; ++i) {
    int x; cin >> x;
    coin.push_back(x);
  }
  f[0] = 1;
  for (int c : coin)
    for (int i = c; i <= n; ++i)
      f[i] += f[i - c];
  cout << f[n] << '\n';
}
