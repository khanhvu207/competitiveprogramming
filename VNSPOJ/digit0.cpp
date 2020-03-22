#include <bits/stdc++.h>

using namespace std;

string s;
int a[30], two[10015], five[10015];

int main() {
  cin >> s;
  for (char c : s) {
    ++a[c - 'a'];
  }
  for (int i = 1; i <= 10000; ++i) {
    int c2 = 0, c5 = 0, t = i;
    while (t % 2 == 0) {
      ++c2;
      t /= 2;
    }
    while (t % 5 == 0) {
      ++c5;
      t /= 5;
    }
    two[i] = c2 + two[i - 1]; 
    five[i] = c5 + five[i - 1];
  }
  int n = s.length();
  for (char c = 'a'; c <= 'z'; ++c) {
    two[n] -= two[a[c - 'a']];
    five[n] -= five[a[c - 'a']];
  }
  cout << min(two[n], five[n]);
}