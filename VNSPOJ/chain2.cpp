#include <iostream>
using namespace std;
struct trie {
  trie *child[26];
  int cnt;
  trie() {
    for (int i = 0; i < 26; ++i)
      child[i] = NULL;
    cnt = 0;
  }
};

int n, res;
trie *root = new trie();

void trieinsert(const string &s) {
  int cnt = 0;
  int m = (int)s.size();
  trie *p = root;
  for (int i = 0; i < m; ++i) {
    int nxt = s[i] - 'a';
    if (p -> child[nxt] == NULL)
      p -> child[nxt] = new trie();
    cnt += p -> cnt;
    p = p -> child[nxt];
  }
  cnt += ++(p -> cnt);
  res = max(res, cnt);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    trieinsert(str);
  }
  cout << res;
}
