/*
 ID: khanhvu2
 LANG: C++11
 TASK: zerosum
*/
#include <iostream>
#include <cstdio>
using namespace std;
int n;

void Try(int x, int y, int z, char c, string s) {
  if (x > n) {
    if (c == '+') z += y;
      else z -= y;
    if (z != 0) return;
    cout << '1';
    for (int i = 0; i < (int)s.size(); ++i)
      cout << s[i] << i + 2; 
    cout << '\n';
  }
  Try(x + 1, y * 10 + x, z, c, s + ' ');
  if (c == '+') z += y;
    else z -= y;
  Try(x + 1, x, z, '+', s + '+');
  Try(x + 1, x, z, '-', s + '-');
}

int main() {
  freopen("zerosum.in", "r", stdin);
  freopen("zerosum.out", "w", stdout);
  cin >> n;
  Try(2, 1, 0, '+', "");
}