#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int> > snode;
const int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int n, m, sx, sy, ex, ey, a[55][55], opt[55][55], dp[55][55], steps[55][55];
priority_queue<snode, vector<snode>, greater<snode> > q;
bool vst[55][55];

int main()
{
    freopen("quanma.inp", "r", stdin);
    freopen("quanma.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            if (a[i][j] == 3)
                sx = i, sy = j;
            else if (a[i][j] == 4)
                ex = i, ey = j;
        }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int k = 0; k <= n * m; ++k)
                opt[i][j] = 1e9;

    steps[sx][sy] = 1;
    opt[sx][sy] = 0;
    q.push({opt[sx][sy], {sx, sy}});

    while (!q.empty())
    {
        int d = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        if (d > opt[x][y]) continue;
        vst[x][y] = 1;
        if (x == ex && y == ey) break;

        for (int i = 0; i < 8; ++i)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X < 1 || X > n || Y < 1 || Y > m || a[X][Y] == 2) continue;
            if (d + (a[X][Y] != 1 ? 1 : 0) <= opt[X][Y])
            {
                if (d + (a[X][Y] != 1 ? 1 : 0) == opt[X][Y])
                    steps[X][Y] += steps[x][y];
                else if (!vst[X][Y])
                {
                    opt[X][Y] = d + (a[X][Y] != 1 ? 1 : 0);
                    steps[X][Y] = steps[x][y];
                    q.push({opt[X][Y], {X, Y}});
                }
            }
        }
    }
    --opt[ex][ey];
    if (opt[ex][ey] == 1e9 - 1)
        cout << -1;
    else if (opt[ex][ey] == 0)
        cout << 0 << '\n' << 1;
    else
        cout << opt[ex][ey] << '\n' << steps[ex][ey];
}
