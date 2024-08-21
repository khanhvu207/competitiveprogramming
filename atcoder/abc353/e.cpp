#include <bits/stdc++.h>

#include <ranges>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#ifdef LOCAL
#include "../../debug.h"
#else
#define debug(...) 42
#endif

namespace utils {
template <typename T>
bool chMax(T& target, const T& value) {
    if (value > target) {
        target = value;
        return true;
    }
    return false;
}

template <typename T>
bool chMin(T& target, const T& value) {
    if (value < target) {
        target = value;
        return true;
    }
    return false;
}
}  // namespace utils
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';


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
        p = nullptr;
        break;
      }
      p = p->c[id];
      ans += p->total_item;
    }
    return ans;
  }
};



void solve() {
    int n;
    cin >> n;
    vector<string> a;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        a.push_back(s);
    }

    string_trie tr;
    ranges::reverse(a);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        string s = a[i];
        res += tr.get_ans(s);
        tr.insert(s);
    }

    cout << res << el;
}

const bool is_multitest = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
