#include <bits/stdc++.h>
using namespace std;
const int N = 100015;

int n, m, h, t, deg[N];
vector<int> g[N];
vector<pair<int, int> > e;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  freopen("hydra.inp", "r", stdin);
  freopen("hydra.out", "w", stdout);
  cin >> n >> m >> h >> t;
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    e.push_back({u, v});
    ++deg[u];
    ++deg[v];
  }
  for (int i = 0; i < m; ++i) {
    int head = e[i].first;
    int tail = e[i].second;
    for (int z = 0; z < 2; ++z, swap(head, tail)) {
      if (deg[head] < h + 1 || deg[tail] < t + 1) continue;
      if (deg[head] >= h + t + 1 && deg[tail] >= h + t + 1) {
        cout << "YES\n";
        cout << head << ' ' << tail << '\n';
        vector<int> tmp;
        for (int x : g[head]) {
          if (x == tail) continue;
          cout << x << ' ';
          --h;
          tmp.push_back(x);
          if (h < 1) break;
        }
        sort(tmp.begin(), tmp.end());
        for (int x : g[tail]) {
          if (binary_search(tmp.begin(), tmp.end(), x) || x == head) continue;
          cout << x << ' ';
          --t;
          if (t < 1) break;
        }
        return 0;
      }
      sort(g[head].begin(), g[head].end());
      vector<int> joint;
      for (int x : g[tail])
        if (binary_search(g[head].begin(), g[head].end(), x))
          joint.push_back(x);
      sort(joint.begin(), joint.end());
      vector<int> ans_head, ans_tail;
      int cnt_head = deg[head] - 1 - (int)joint.size();
      int cnt_tail = deg[tail] - 1 - (int)joint.size();
      for (int x : g[head])
        if (!binary_search(joint.begin(), joint.end(), x) && x != tail)
          ans_head.push_back(x);
      for (int x : g[tail])
        if (!binary_search(joint.begin(), joint.end(), x) && x != head)
          ans_tail.push_back(x);
      while ((int)ans_head.size() < h && !joint.empty()) {
        ans_head.push_back(joint[(int)joint.size() - 1]);
        joint.pop_back();
      }
      while ((int)ans_tail.size() < t && !joint.empty()) {
        ans_tail.push_back(joint[(int)joint.size() - 1]);
        joint.pop_back();
      }
      if ((int)ans_head.size() == h && (int)ans_tail.size() == t) {
        cout << "YES\n";
        cout << head << ' ' << tail << '\n';
        for (int x : ans_head)
          cout << x << ' '; cout << '\n';
        for (int x : ans_tail)
          cout << x << ' ';
        return 0;
      }
    }
  }
  cout << "NO\n";
}
