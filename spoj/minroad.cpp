#include <bits/stdc++.h>
using namespace std;
const int N = 300015;

int n, a, b, p[2][N];
vector<pair<int, int> > c;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> a >> b;
  for (int i = 0; i < n; ++i) {
    int d, tree;
    cin >> d >> tree;
    c.push_back(make_pair(d, tree));
  }
  sort(c.begin(), c.end());
  for (int i = 0; i < n; ++i)
    p[0][i] = (i != 0 ? p[0][i - 1] : 0) + (c[i].second == 1);
  for (int i = 0; i < n; ++i)
    p[1][i] = (i != 0 ? p[1][i - 1] : 0) + (c[i].second == 2);
  int res = 2e9;
  int l = 0;
  for (int r = 0; r < n; ++r) {
    while (p[0][r] - (l != 0 ? p[0][l - 1] : 0) >= a && p[1][r] - (l != 0 ? p[1][l - 1] : 0) >= b) {
      res = min(res, c[r].first - c[l].first);
      ++l;
    }
  }
  if (res == 2e9)
    res = -1;
  cout << res;
}
