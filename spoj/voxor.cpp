#include <iostream>
using namespace std;
struct trie {
  trie *bit[2];
  int cnt;
  trie() {
    bit[0] = bit[1] = NULL;
    cnt = 0;
  }
};

int n, q, flip[35];
trie *root = new trie();

void trieinsert(int x) {
  trie *p = root;
  for (int i = 30; i >= 0; --i) {
    int nxt = (x >> i) & 1;
    if (p -> bit[nxt] == NULL)
      p -> bit[nxt] = new trie();
    ++(p -> cnt);
    p = p -> bit[nxt];
  }
  ++(p -> cnt);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> q;
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    trieinsert(x);
  }
  while (q--) {
    string query;
    cin >> query;
    if (query == "XOR") {
      int x;
      cin >> x;
      for (int i = 30; i >= 0; --i)
        if ((x >> i) & 1)
          flip[i] ^= 1;
    } else {
      int x;
      cin >> x;
      x = n - x + 1;
      int res = 0;
      trie *p = root;
      for (int i = 30; i >= 0; --i)
        if (p -> bit[0 ^ flip[i]] != NULL && p -> bit[0 ^ flip[i]] -> cnt >= x) {
          res <<= 1;
          p = p -> bit[0 ^ flip[i]];
        } else if (p -> bit[1 ^ flip[i]] != NULL) {
          if (p -> bit[0 ^ flip[i]] != NULL)
            x -= p -> bit[0 ^ flip[i]] -> cnt;
          res = res << 1 | 1;
          p = p -> bit[1 ^ flip[i]];
        }
      cout << res << '\n';
    }
  }
}
