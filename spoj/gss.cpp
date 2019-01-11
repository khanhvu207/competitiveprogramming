#include <bits/stdc++.h>
using namespace std;
const int N = 50015;
struct node {
  int left, ans, right, sum;
} st[N * 4];
int n;
int a[N], prefix[N];

node combine(const node &a, const node &b) {
  node res;
  res.left = max(a.left, a.sum + b.left);
  res.right = max(b.right, b.sum + a.right);
  res.ans = max(a.right + b.left, max(a.ans, b.ans));
  res.sum = a.sum + b.sum;
  return res;
}

void build(int id, int tl, int tr) {
  if (tl == tr) {
    st[id].left = a[tl];
    st[id].right = a[tl];
    st[id].ans = a[tl];
    st[id].sum = a[tl];
    return;
  }
  int tm = (tl + tr) >> 1;
  build(id << 1, tl, tm);
  build(id << 1 | 1, tm + 1, tr);
  st[id] = combine(st[id << 1], st[id << 1 | 1]);
}

node query(int id, int tl, int tr, int L, int R) {
  if (tr < L || R < tl) {
    node tmp;
    tmp.left = tmp.right = -1e9;
    tmp.ans = -1e9;
    tmp.sum = 0;
    return tmp;
  }
  if (L <= tl && tr <= R)
    return st[id];
  int tm = (tl + tr) >> 1;
  return combine(query(id << 1, tl, tm, L, R), query(id << 1 | 1, tm + 1, tr, L, R));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i];
  build(1, 1, n);
  int tc;
  cin >> tc;
  while (tc--) {
    int l, r;
    cin >> l >> r;
    node res = query(1, 1, n, l, r);
    cout << res.ans << '\n';
  }
}
