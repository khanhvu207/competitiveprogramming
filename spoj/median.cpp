#include <iostream>
using namespace std;
const int mod = 65536;
const int N = 250015;
struct trie {
  trie *bit[2];
  int cnt;
  trie() {
    bit[0] = bit[1] = NULL;
    cnt = 0;
  }
};

trie *root = new trie();
long long seed, mul, add, n, k, a[N];

void trieinsert(long long x) {
  trie *p = root;
  for (int i = 30; i >= 0; --i) {
    int nxt = (x >> i) & 1ll;
    if (p -> bit[nxt] == NULL)
      p -> bit[nxt] = new trie();
    ++(p -> cnt);
    p = p -> bit[nxt];
  }
  ++(p -> cnt);
}

void triedel(long long x) {
  trie *p = root;
  for (int i = 30; i >= 0; --i) {
    int nxt = (x >> i) & 1ll;
    --(p -> bit[nxt] -> cnt);
    if (p -> bit[nxt] -> cnt == 0) {
      p -> bit[nxt] = NULL;
      return;
    } else
      p = p -> bit[nxt];
  }
}

long long get(int kth) {
  long long res = 0;
  trie *p = root;
  for (int i = 30; i >= 0; --i)
    if (p -> bit[0] != NULL && p -> bit[0] -> cnt >= kth) {
      res = res << 1ll;
      p = p -> bit[0];
    } else if (p -> bit[1] != NULL) {
      if (p -> bit[0] != NULL)
        kth -= p -> bit[0] -> cnt;
      res = res << 1ll | 1ll;
      p = p -> bit[1];
    }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int tc;
  cin >> tc;
  for (int C = 1; C <= tc; ++C) {
    root = new trie();
    cin >> seed >> mul >> add >> n >> k;
    a[0] = seed % mod;
    for (int i = 1; i < n; ++i) {
      a[i] = (a[i - 1] * mul) % mod + add % mod;
      a[i] %= mod;
    }
    for (int i = 0; i < k; ++i)
      trieinsert(a[i]);
    long long res = get((k + 1) / 2);
    for (int l = 1, r = k; r < n; ++l, ++r) {
      triedel(a[l - 1]);
      trieinsert(a[r]);
      res += get((k + 1) / 2);
    }
    cout << "Case #" << C << ": " << res << '\n';
  }
}
