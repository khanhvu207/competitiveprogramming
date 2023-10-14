/*
ID: khanhvu2
LANG: C++14
TASK: maze1
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXSIZE = 250;

int w, h, res = 0;
int step[MAXSIZE][MAXSIZE], answer[MAXSIZE][MAXSIZE];
char maze[MAXSIZE][MAXSIZE];
const int movex[4] = {-1, 0, 1, 0};
const int movey[4] = {0, 1, 0, -1};

bool isExit(int i, int j) {
  bool chk = false;
  chk |= (maze[i-1][j] == ' ' && i-2<0);
  chk |= (maze[i+1][j] == ' ' && i+2==2*h+1);
  chk |= (maze[i][j-1] == ' ' && j-2<0);
  chk |= (maze[i][j+1] == ' ' && j+2==2*w+1);
  return chk;
}

void bfs(int x, int y) {
  memset(step, -1, sizeof step);
  queue<pair<int, int>> q;
  q.push({x, y});
  step[x][y] = 1;

  while (!q.empty()) {
    x = q.front().first;
    y = q.front().second;
    q.pop();
    answer[x][y] = min(answer[x][y], step[x][y]);

    for (int i=0; i<4; ++i) {
      int nxt_x = x+movex[i];
      int nxt_y = y+movey[i];
      if (nxt_x == 0 || nxt_x == 2*h || nxt_y == 0 || nxt_y == 2*w) continue;
      if (maze[nxt_x][nxt_y] != ' ') continue;
      nxt_x += movex[i];
      nxt_y += movey[i];
      if (step[nxt_x][nxt_y] != -1) continue;
      step[nxt_x][nxt_y] = step[x][y]+1;
      q.push({nxt_x, nxt_y});
    }
  }
}

int main() {
  freopen("maze1.in", "r", stdin);
  freopen("maze1.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> w >> h;
  string line;
  getline(cin, line);
  
  for (int i=0; i<2*h+1; ++i) {
    getline(cin, line);
    for (int j=0; j<(int)line.size(); ++j) {
      maze[i][j] = line[j];
      answer[i][j] = 999999;
    }
  }

  for (int i=1; i<2*h; i+=2)
    for (int j=1; j<2*w; j+=2) 
      if (maze[i][j] == ' ' && isExit(i, j)) { 
        bfs(i, j);
      }

  for (int i=1; i<2*h; i+=2) 
    for (int j=1; j<2*w; j+=2) 
      res = max(res, answer[i][j]);

  cout << res << '\n';
}