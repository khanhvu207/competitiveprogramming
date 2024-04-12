template<typename T>
class binary_trie {
  struct trie {
    trie* bit[2];
    int cnt;
    trie() {
      bit[0] = bit[1] = nullptr;
      cnt = 0;
    }
  };

  static constexpr int nb = std::is_same<T, int>::value ? 30 : 62;

public:
  trie* root = new trie();
  binary_trie() {}
  binary_trie(int n) : nb(n) {}

  void insert(T x) {
    trie* p = root;
    for (int i = nb; i >= 0; --i) {
      int nxt = (x >> i) & 1;
      if (p->bit[nxt] == nullptr)
        p->bit[nxt] = new trie();
      ++(p->cnt);
      p = p->bit[nxt];
    }
    ++(p->cnt);
  }

  void erase(T x) {
    trie* p = root;
    for (int i = nb; i >= 0; --i) {
      int nxt = (x >> i) & 1;
      --(p->bit[nxt]->cnt);
      if (p->bit[nxt]->cnt == 0) {
        p->bit[nxt] = nullptr;
        return;
      } else
        p = p->bit[nxt];
    }
  }

  T get(int kth) {
    T res = 0;
    trie* p = root;
    for (int i = nb; i >= 0; --i)
      if (p->bit[0] != nullptr && p->bit[0]->cnt >= kth) {
        res = res << 1;
        p = p->bit[0];
      } else if (p->bit[1] != nullptr) {
        if (p->bit[0] != nullptr)
          kth -= p->bit[0]->cnt;
        res = res << 1 | 1;
        p = p->bit[1];
      }
    return res;
  }
};
