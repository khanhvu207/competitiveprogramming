#include <iostream>
#include <cstdio>
using namespace std;
const int N = 115;
const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int n, m, res;
int deg[N][N];
char c[N][N];
bool ok, vis[N][N];

void DFS(int x, int y)
{
    //cerr << x << ' ' << y << '\n';
    vis[x][y] = true;
    deg[x][y] = 0;
    for (int i = 0; i < 8; ++i)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m || c[xx][yy] == '.') continue;
        ++deg[x][y];
        if (!vis[xx][yy])
            DFS(xx, yy);
    }
    ok &= (deg[x][y] == 2);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("hoavan.inp", "r", stdin);
    freopen("hoavan.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> c[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!vis[i][j] && c[i][j] == '#') {
                ok = true;
                DFS(i, j);
                if (ok) ++res;
            }
    cout << res;
}
