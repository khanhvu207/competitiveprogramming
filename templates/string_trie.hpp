class string_trie {
  struct trie {
    trie* c[26];
    trie() {
      for (int i = 0; i < 26; ++i)
        c[i] = nullptr;
    }
    ll total_len = 0;
    ll total_item = 0;
  };

public:
  trie* root = new trie();
  string_trie() {}

  void insert(string x) {
    trie* p = root;
    int len = (int)x.size();
    p->total_len += len;
    p->total_item += 1;
    for (int i = 0; i < len; ++i) {
      int id = x[i] - 'a';
      if (p->c[id] == nullptr)
        p->c[id] = new trie();
      p = p->c[id];
      p->total_len += len - i - 1;
      p->total_item += 1;
    }
  }

  ll get_ans(string x) {
    trie* p = root;
    int len = (int)x.size();
    ll ans = 0;
    for (int i = 0; i < len; ++i) {
      int id = x[i] - 'a';
      if (p->c[id] == nullptr) {
        ans += p->total_len + (len-i)*p->total_item;
        p = nullptr;
        break;
      }
      ll subtree_total_item = p->c[id]->total_item;
      ll subtree_total_len = p->c[id]->total_len + subtree_total_item;
      ans += (p->total_len - subtree_total_len) + (len-i)*(p->total_item - subtree_total_item);
      p = p->c[id];
    }
    if (p != nullptr)
      ans += p->total_len;
    return ans;
  }
};

