#include <bits/stdc++.h>
using namespace std;

/**
 * Binary trie data structure
 * Stores numbers as binary strings
 */
struct trie {
  trie *bit[2];
  int cnt;
  trie() {
    bit[0] = bit[1] = NULL;
    cnt = 0;
  }
};

trie *root = new trie();

/**
 * Insert a number to the trie
 * Time complexity: O(log(x))
 * 
 * @param: x - A number to be inserted
 */
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

/**
 * Remove a number to the trie
 * Time complexity: O(log(x))
 * 
 * @param: x - A number to be removed
 */
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

/**
 * Get the k-th number in the trie (sorted ascending)
 * Time complexity: O(log(x))
 * 
 * @param x - A number to be removed
 * @return k-th number
 */
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
    trieinsert(1);
    trieinsert(2);
    trieinsert(3);
    trieinsert(4);
    
    cout << get(3) << '\n';
    // Return 3
    return 0;
}