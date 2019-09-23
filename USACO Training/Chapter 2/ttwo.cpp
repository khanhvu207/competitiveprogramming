/*
ID: khanhvu2
LANG: C++14
TASK: ttwo
*/
#include <bits/stdc++.h>
using namespace std;

int dirCows, dirJohn, timer;
char maze[10][10];
bool chkCows = true, chkJohn = true;
bool vstCows[10][10][4], vstJohn[10][10][4];
pair<int, int> posCows, posJohn;
const int movex[4] = {-1, 0, 1, 0};
const int movey[4] = {0, 1, 0, -1};

int main() {
  freopen("ttwo.in", "r", stdin);
  freopen("ttwo.out", "w", stdout);
  
  for (int i=0; i<10; ++i)
    for (int j=0; j<10; ++j) {
      cin >> maze[i][j];
      if (maze[i][j] == 'C')
        posCows = {i, j};
      else if (maze[i][j] == 'F')
        posJohn = {i, j};
    }

  for (int i=0; i<1000; ++i) {
    if (posCows.first+movex[dirCows] < 0 || posCows.first+movex[dirCows] == 10 
        || posCows.second+movey[dirCows] < 0 || posCows.second+movey[dirCows] == 10 || 
        maze[posCows.first+movex[dirCows]][posCows.second+movey[dirCows]] == '*') 
          dirCows = (dirCows+1)%4;
    else {
      posCows.first += movex[dirCows];
      posCows.second += movey[dirCows];
      chkCows &= !vstCows[posCows.first][posCows.second][dirCows];
      vstCows[posCows.first][posCows.second][dirCows] = true;
    }

    if (posJohn.first+movex[dirJohn] < 0 || posJohn.first+movex[dirJohn] == 10 
        || posJohn.second+movey[dirJohn] < 0 || posJohn.second+movey[dirJohn] == 10 || 
        maze[posJohn.first+movex[dirJohn]][posJohn.second+movey[dirJohn]] == '*') 
          dirJohn = (dirJohn+1)%4;
    else {
      posJohn.first += movex[dirJohn];
      posJohn.second += movey[dirJohn];
      chkJohn &= !vstJohn[posJohn.first][posJohn.second][dirJohn];
      vstJohn[posJohn.first][posJohn.second][dirJohn] = true;
    }

    ++timer;
    if (posCows == posJohn) {
      cout << timer << '\n';
      return 0;
    }
  }
  cout << 0 << '\n';
  return 0;
}