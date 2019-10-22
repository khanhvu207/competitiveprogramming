/*
ID: khanhvu2
LANG: C++14
TASK: shopping
*/
#include <bits/stdc++.h>
using namespace std;

const int inf = numeric_limits<int>::max();
int n, m, p[1000], pOffer[1000], need[1000], item_id[1000], rev_id[1000];
int f[100][6][6][6][6][6];
pair<int, int> d[100];
vector<pair<int, int>> offer[100];

int dp(int cur, int cnt[]) {
  if (f[cur][cnt[0]][cnt[1]][cnt[2]][cnt[3]][cnt[4]] != -1) return f[cur][cnt[0]][cnt[1]][cnt[2]][cnt[3]][cnt[4]];
  int res = 1e9;
  if (cur == n) {
    res = 0;
    for (int i = 0; i < 5; ++i) {
      res += cnt[i] * p[item_id[i]];
    }
    f[cur][cnt[0]][cnt[1]][cnt[2]][cnt[3]][cnt[4]] = res;
    return res;
  }
  for (int i = 0; i < 100; ++i) {
    int tmp_n[5];
    bool chk = true;
    for (int r = 0; r < 5; ++r) tmp_n[r] = cnt[r];
    for (pair<int, int> item : offer[cur]) {
      int id = rev_id[item.first];
      tmp_n[id] -= i * item.second;   
      chk &= tmp_n[id] >= 0;
    }
    if (!chk) break;
    res = min(res, i * pOffer[cur] + dp(cur + 1, tmp_n));
  }
  f[cur][cnt[0]][cnt[1]][cnt[2]][cnt[3]][cnt[4]] = res;
  return res;
}

int main() {
  freopen("shopping.in", "r", stdin);
  freopen("shopping.out", "w", stdout);
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    while (k--) {
      int id, val;
      cin >> id >> val;
      offer[i].push_back({id, val});
    }
    cin >> d[i].first;
    d[i].second = i;
    pOffer[i] = d[i].first;
  }
  cin >> m;
  int tmpNeed[5] = {0};
  for (int i = 0; i < m; ++i) {
    int id;
    cin >> id;
    item_id[i] = id;
    rev_id[id] = i;
    cin >> need[id] >> p[id];
    tmpNeed[i] = need[id];
  }
  memset(f, -1, sizeof f);
  cout << dp(0, tmpNeed) << '\n';
  return 0;
}