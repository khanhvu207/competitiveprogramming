#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, s, n, f;
  cin >> t >> s >> n >> f;

  using dt = pair<bool, double>;
  vector<vector<double>> dp(55, vector<double>(1250));
  vector<vector<dt>> threshold(55, vector<dt>(1250));

  function<double(int)> calc = [&](int u) {
    if (f == 2) {
      return cbrt(1.0 * (u - 600) / 10.0);
    }
    else {
      return (u - 600.0) * (u - 600.0) / 100.0;
    }
  };

  for (int j = 0; j <= 1200; ++j)
    dp[0][j] = calc(j);

  for (int i = 1; i <= 50; ++i) {
    for (int j = 10; j <= 1190; ++j) {
      double not_play = dp[i-1][j-1];
      double play_lose = dp[i-1][j-10];
      double play_win = dp[i-1][j+10];
      if (not_play > max(play_lose, play_win)) {
        dp[i][j] = not_play;
        threshold[i][j] = {false, 0};
      }
      else if (not_play < min(play_lose, play_win)) {
        dp[i][j] = (play_lose + play_win) / 2.0;
        threshold[i][j] = {true, 0};
      }
      else if (play_lose < play_win) {
        double x = (not_play - play_lose) / (play_win - play_lose);
        dp[i][j] = x * not_play + (0.5 - 0.5 * x * x) * play_win + (0.5 + 0.5 * x * x - x) * play_lose;
        threshold[i][j] = {true, x};
      }
      else {
        double x = (not_play - play_lose) / (play_win - play_lose);
        dp[i][j] = (1-x) * not_play + (0.5 * x * x) * play_win + (x - 0.5 * x * x) * play_lose;
        threshold[i][j] = {false, x};
      }
    }
  }

  for (int i = 0; i < t; ++i) {
    int cur_s = s * 10 + 600;
    int cur_n = n;
    for (int j = 0; j < n; ++j) {
      double p;
      cin >> p;
      if (f == 1) {
        if (p >= 0.45) {
          cout << 1 << endl;
          int r;
          cin >> r;
          cur_s += (2*r-1) * 10;
        }
        else {
          cout << 0 << endl;
          cur_s -= 1;
        }
      }
      else {
        auto [up, x] = threshold[cur_n][cur_s];
        if ((up && p > x) || (!up && p < x)) {
          cout << 1 << endl;
          int r;
          cin >> r;
          cur_s += (2 * r - 1) * 10;
        }
        else {
          cout << 0 << endl;
          cur_s -= 1;
        }
      }
      
      --cur_n;
    }
  }
}
