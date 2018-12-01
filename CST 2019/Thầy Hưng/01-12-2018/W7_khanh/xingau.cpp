#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};

int n, m;
char a[55][55];
bool vst[55][55], rvst[55][55];
vector<int> ans;
vector<pair<int, int> > dice;

void floodfill (int x, int y)
{
    vst[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (a[X][Y] == '.' || X < 0 || X >= n || Y < 0 || Y >= m || vst[X][Y]) continue;
        floodfill(X, Y);
    }
    dice.push_back(make_pair(x, y));
    rvst[x][y] = false;
}

void dfs (int x, int y)
{
    rvst[x][y] = true;
    for (int i = 0; i < 4; ++i)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (a[X][Y] != 'X' || X < 0 || X >= n || Y < 0 || Y >= m || rvst[X][Y]) continue;
        dfs(X, Y);
    }
}

int main()
{
    freopen("xingau.inp", "r", stdin);
    freopen("xingau.out", "w", stdout);

    cin >> m >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] != '.' && !vst[i][j])
            {
                dice.clear();
                floodfill(i, j);
                int cnt = 0;
                for (int i = 0; i < (int)dice.size(); ++i)
                    if (!rvst[dice[i].first][dice[i].second] && a[dice[i].first][dice[i].second] == 'X')
                        dfs(dice[i].first, dice[i].second), ++cnt;
                ans.push_back(cnt);
            }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); ++i)
        cout << ans[i] << ' ';
}
