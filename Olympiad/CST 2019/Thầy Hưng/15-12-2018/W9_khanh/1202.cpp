#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 222;
const int inf = 1e9;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
typedef pair<int, pair<int, int> > col;

int n, k, m[N][N][10], lft, up, sx, sy, d[N][N];
bool vis[N][N];
set<pair<int, int> > s;
priority_queue<col, vector<col>, greater<col> > heap;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("1202.inp", "r", stdin);
    freopen("1202.out", "w", stdout);

    while (cin >> n >> k)
    {
        if (n < 0 && k < 0) return 0;
        lft = -1, up = -1;
        memset(m, 0, sizeof m);
        for (int i = 0; i < n; ++i)
        {
            int x, y, D, len;
            cin >> x >> y >> D >> len;
            lft = max(lft, x);
            up = max(up, y);
            for (int j = 0; j < len; ++j)
            {
                int X = x + (!D) * j;
                int Y = y + D * j;
                if (D)
                {
                    m[X][Y][1 << 3] = 1;
                    m[X - 1][Y][1 << 1] = 1;
                    //s.insert({X, Y});
                    //s.insert({X - 1, Y});
                } else
                {
                    m[X][Y][1 << 2] = 1;
                    m[X][Y - 1][1 << 0] = 1;
                    //s.insert({X, Y});
                    //s.insert({X, Y - 1});
                }
            }
        }
        for (int i = 0; i < k; ++i)
        {
            int x, y, D;
            cin >> x >> y >> D;
            lft = max(lft, x);
            up = max(up, y);
            if (D)
            {
                m[x][y][1 << 3] = 2;
                m[x - 1][y][1 << 1] = 2;
                //.insert({x - 1, y});
            } else
            {
                m[x][y][1 << 2] = 2;
                m[x][y - 1][1 << 0] = 2;
                //s.insert({x, y});
                //s.insert({x, y - 1});
            }
        }
        double x, y;
        cin >> x >> y;
        sx = floor(x), sy = floor(y);

        for (int i = 0; i <= 215; ++i)
            for (int j = 0; j <= 215; ++j)
                d[i][j] = inf, vis[i][j] = false;
        d[sx][sy] = 0;
        heap.push({0, {sx, sy}});
        int res = inf;
        while (!heap.empty())
        {
            int doors = heap.top().first;
            int x = heap.top().second.first;
            int y = heap.top().second.second;
            heap.pop();
            if (doors > d[x][y]) continue;
            vis[x][y] = true;
            if (m[x][y][1] == 0 || m[x][y][2] == 0 || m[x][y][4] == 0 || m[x][y][8] == 0)
            {
                res = min(res, doors);
                continue;
            }
            for (int i = 0; i < 4; ++i)
            {
                int X = x + dx[i];
                int Y = y + dy[i];
                if (m[x][y][1 << i] == 1) continue;
                if (!vis[X][Y] && doors + (m[x][y][1 << i] == 2) < d[X][Y])
                {
                    //cerr << x << ' ' << y << "->" << X << ' ' << Y << '\n';
                    d[X][Y] = doors + (m[x][y][1 << i] == 2);
                    heap.push({d[X][Y], {X, Y}});
                }
            }
        }
        if (res == inf)
            cout << -1 << '\n';
        else
            cout << res << '\n';
    }
}
