#include <iostream>
using namespace std;
const int N = 300015;
const int mod = 1337377;
struct trie {
  trie *child[26];
  int cnt;
  trie() {
    for (int i = 0; i < 26; ++i)
      child[i] = NULL;
    cnt = 0;
  }
};

int n, dp[N];
trie *root = new trie();

void trieinsert(const string &s) {
  int m = (int)s.size();
  trie *p = root;
  for (int i = 0; i < m; ++i) {
    int nxt = s[i] - 'a';
    if (p -> child[nxt] == NULL)
      p -> child[nxt] = new trie();
    p = p -> child[nxt];
  }
  ++(p -> cnt);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  string s;
  cin >> s;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    trieinsert(str);
  }
  int k = (int)s.size();
  dp[k] = 1ll;
  for (int i = k - 1, j; i >= 0; --i) {
    int cnt = 0;
    trie *p = root;
    for (j = i; j < k; ++j) {
      int nxt = s[j] - 'a';
      if (p -> child[nxt] == NULL)
        break;
      if (p -> cnt > 0)
        cnt = (cnt + dp[j]) % mod;
      p = p -> child[nxt];
    }
    if (p -> cnt > 0)
      cnt = (cnt + dp[j]) % mod;
    dp[i] = cnt;
  }
  cout << dp[0];
}
