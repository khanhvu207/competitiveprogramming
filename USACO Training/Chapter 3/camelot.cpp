/*
ID: khanhvu2
LANG: C++14
TASK: camelot
*/
#include <bits/stdc++.h>
using namespace std;

const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int n, m, cnt[33][33], mask[800][33][33][2];
bool vst[800][33][33][2];
pair<int, int> king;
vector<pair<int, int>> knights;

struct Node {
  int x, y, d;
  bool flag;
  Node(int xx, int yy, int dd, bool flagg) : x(xx), y(yy), d(dd), flag(flagg) {}
  bool operator < (const Node& other) const {
    return d > other.d;
  }
};

int distKing(int x, int y) {
  int steps = 0;
  if (abs(x - king.first) < abs(y - king.second)) {
    x -= (x - king.first);
    steps += abs(x - king.first);
  } 
  else {
    y -= (y - king.second);
    steps += abs(y - king.second);
  }
  return steps + abs(x - king.first) + abs(y - king.second);
}

void BFS(int id, int x, int y) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      mask[id][i][j][1] = 1e5;
      mask[id][i][j][0] = 1e5;
    }
  }
  priority_queue<Node> Q;
  mask[id][x][y][0] = 0;
  mask[id][x][y][1] = distKing(x, y);
  Q.push(Node(x, y, mask[id][x][y][0], false));
  Q.push(Node(x, y, mask[id][x][y][1], true));
  while (!Q.empty()) {
    int x = Q.top().x;
    int y = Q.top().y;
    int d = Q.top().d;
    bool hasKing = Q.top().flag;
    Q.pop();
    if (d > mask[id][x][y][hasKing]) continue;
    vst[id][x][y][hasKing] = true;
    for (int i = 0; i < 8; ++i) {
      int nxt_x = x + dx[i];
      int nxt_y = y + dy[i];
      if (nxt_x < 1 || nxt_x > n || nxt_y < 1 || nxt_y > m) continue;
      if (!hasKing) {
        if (!vst[id][nxt_x][nxt_y][false] && d + 1 < mask[id][nxt_x][nxt_y][false]) {
          mask[id][nxt_x][nxt_y][false] = d + 1;
          Q.push(Node(nxt_x, nxt_y, mask[id][nxt_x][nxt_y][false], false));
        }
        if (!vst[id][nxt_x][nxt_y][true] && d + 1 + distKing(nxt_x, nxt_y) < mask[id][nxt_x][nxt_y][true]) {
          mask[id][nxt_x][nxt_y][true] = d + 1 + distKing(nxt_x, nxt_y);
          Q.push(Node(nxt_x, nxt_y, mask[id][nxt_x][nxt_y][true], true));
        }
        continue;
      }
      if (!vst[id][nxt_x][nxt_y][true] && d + 1 < mask[id][nxt_x][nxt_y][true]) {
        mask[id][nxt_x][nxt_y][true] = d + 1;
        Q.push(Node(nxt_x, nxt_y, mask[id][nxt_x][nxt_y][true], true));
      }
    }
  }
} 

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  freopen("camelot.in", "r", stdin);
  freopen("camelot.out", "w", stdout);
  cin >> n >> m;
  char col;
  int row;
  cin >> col >> row;
  king = {row, col - 'A' + 1};
  while (cin >> col >> row) {
    knights.push_back({row, col - 'A' + 1});
  }
  for (int i = 0; i < knights.size(); ++i) {
    BFS(i, knights[i].first, knights[i].second);
  }
  int res = numeric_limits<int>::max();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      for (int k = 0; k < knights.size(); ++k) {
        cnt[i][j] += mask[k][i][j][0];
      }
      for (int k = 0; k < knights.size(); ++k) {
        int t = cnt[i][j] - mask[k][i][j][0] + mask[k][i][j][1];
        res = min(res, t);
      }
    }
  }
  if (res == numeric_limits<int>::max()) {
    res = 0;
  }
  cout << res << '\n';
}
