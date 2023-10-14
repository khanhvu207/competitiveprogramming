#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

int n, m, k;
char a[315][315], word[90015];
bool vst[315][315], mark[90015], chk[90015];
int num[90015], color[315][315];
set<int> s;
vector<vector<int> > g;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void dfs (int x, int y, int col)
{
    ++num[col];
    vst[x][y] = 1;
    color[x][y] = col;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m || vst[xx][yy] || a[xx][yy] != a[x][y]) continue;
        dfs(xx, yy, col);
    }
}

void scout (int x, int y)
{
    vst[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if (color[xx][yy] != color[x][y])
        {
            s.insert(color[xx][yy]);
            continue;
        }
        if (!vst[xx][yy]) scout(xx, yy);
    }
}

int get (int u)
{
    chk[u] = 1;
    int cnt = num[u];
    for (int i = 0; i < (int)g[u].size(); i++)
        if (mark[g[u][i]] && !chk[g[u][i]]) cnt += get(g[u][i]);
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("mecung.inp", "r", stdin);
    freopen("mecung.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int c = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vst[i][j])
                dfs(i, j, ++c), word[c] = a[i][j];
    g.resize(c + 1);
    memset(vst, 0, sizeof vst);
    memset(mark, 0, sizeof mark);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vst[i][j])
            {
                s.clear();
                scout(i, j);
                set<char> nb;
                for (set<int>::iterator it = s.begin(); it != s.end(); it++)
                    g[color[i][j]].push_back(*it),
                    nb.insert(word[*it]);
                mark[color[i][j]] = (int)nb.size() < k ? 0 : 1;
            }
    int res = 0;
    for (int i = 1; i <= c; i++)
    {
        if (!mark[i]) continue;
        memset(chk, 0, sizeof chk);
        int v = get(i);
        res = max(res, v);
    }
    cout << res;
    return 0;
}
