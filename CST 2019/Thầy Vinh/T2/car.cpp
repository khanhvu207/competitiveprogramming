#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

typedef pair<pair<int, int>, int> data;

int n, m, sx, sy, k;
char ms[115][115];
map<string, int> cmd;
int code[1015];
bool vst[115][115][1015];
queue<data> q;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("car.inp", "r", stdin);
    freopen("car.out", "w", stdout);
    cmd["UP"] = 0;
    cmd["DOWN"] = 1;
    cmd["LEFT"] = 2;
    cmd["RIGHT"] = 3;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> ms[i][j];
            if (ms[i][j] == 'S')
                sx = i, sy = j;
        }
    ms[sx][sy] = '.';
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        string s;
        cin >> s;
        code[i] = cmd[s];
    }
    q.push({{sx, sy}, 0});
    while (!q.empty())
    {
        data T = q.front(); q.pop();
        int cur = T.second;
        int x = T.first.first + dx[code[cur]];
        int y = T.first.second + dy[code[cur]];
        //cerr << T.first.first << ' ' << T.first.second << ' ' << x << ' ' << y << '\n';
        if (!(x < 0 || x >= n || y < 0 || y >= m) && !vst[x][y][cur] && ms[x][y] != '#')
            vst[x][y][cur] = 1,
            q.push({{x, y}, cur});
        if (cur + 1 < k)
        {
            x = T.first.first + dx[code[cur + 1]];
            y = T.first.second + dy[code[cur + 1]];
            if (!(x < 0 || x >= n || y < 0 || y >= m) && !vst[x][y][cur + 1] && ms[x][y] != '#'
                && vst[T.first.first][T.first.second][cur])
                vst[x][y][cur + 1] = 1,
                q.push({{x, y}, cur + 1});
        }
        if (cur == k - 1)
            ms[T.first.first][T.first.second] = '*';
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cout << ms[i][j];
            if (j == m - 1) cout << '\n';
        }
    return 0;
}
