#include <iostream>
using namespace std;
const int N = 50015;
struct node {
  int val, lazy;
};
node st[N * 4];
int n, m;

void push(int id) {
  int t = st[id].lazy;
  st[id].lazy = 0;
  st[id << 1].val += t;
  st[id << 1].lazy += t;
  st[id << 1 | 1].val += t;
  st[id << 1 | 1].lazy += t;
}

void update(int id, int tl, int tr, int L, int R, int v) {
  if (tr < L || R < tl)
    return;
  if (L <= tl && tr <= R) {
    st[id].val += v;
    st[id].lazy += v;
    return;
  }
  int tm = (tr + tl) >> 1;
  push(id);
  update(id << 1, tl, tm, L, R, v);
  update(id << 1 | 1, tm + 1, tr, L, R, v);
  st[id].val = max(st[id << 1].val, st[id << 1 | 1].val);
}

int getmax(int id, int tl, int tr, int L, int R) {
  if (tr < L || R < tl)
    return -1e9;
  if (L <= tl && tr <= R)
    return st[id].val;
  int tm = (tr + tl) >> 1;
  push(id);
  return max(getmax(id << 1, tl, tm, L, R), getmax(id << 1 | 1, tm + 1, tr, L, R));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  while (m--) {
    int type;
    cin >> type;
    if (type == 0) {
      int l, r, v;
      cin >> l >> r >> v;
      update(1, 1, n, l, r, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << getmax(1, 1, n, l, r) << '\n';
    }
  }
}
