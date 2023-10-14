#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m;
bool vst[515][515];
long long res = 1e18;
long long d[515][515], v[515][515];
struct data
{
    int x, y;
    long long c;
    bool operator < (const data &r) const
    {
        return c > r.c;
    }
};
priority_queue<data> q;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
data data_ (int uu, int vv, long long cc)
{
    data tmp;
    tmp.x = uu;
    tmp.y = vv;
    tmp.c = cc;
    return tmp;
}
long long dijkstra ()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = 1e18;
    for (int i = 1; i <= n; i++)
    {
        d[i][1] = v[i][1];
        q.push(data_(i, 1, d[i][1]));
    }
    memset(vst, false, sizeof vst);
    while (!q.empty())
    {
        data T = q.top(); q.pop();
        if (T.c > d[T.x][T.y]) continue;
        vst[T.x][T.y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int X = T.x + dx[i];
            int Y = T.y + dy[i];
            if (X < 1 || X > n || Y < 1 || Y > m) continue;
            if (!vst[X][Y] && (d[T.x][T.y] + v[X][Y] < d[X][Y]))
            {
                d[X][Y] = d[T.x][T.y] + v[X][Y];
                q.push(data_(X, Y, d[X][Y]));
            }
        }
    }
    long long tmp = 1e18;
    for (int i = 1; i <= n; i++)
        tmp = min(tmp, d[i][m]);
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("FAIR.INP", "r", stdin);
    freopen("FAIR.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> v[i][j];
    cout << dijkstra();
    return 0;
}
