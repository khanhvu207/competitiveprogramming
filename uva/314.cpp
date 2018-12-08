#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
const int dx[4]={-1, 0, 1, 0};
const int dy[4]={0, 1, 0, -1};

int n, m, sx, sy, ex, ey, d;
int a[55][55], s[55][55], dist[55][55][5];
bool vst[55][55][5];
map<string, int> md;

void Input()
{
    memset(a, 0, sizeof a);
    memset(s, 0, sizeof s);
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin >> a[i][j];
    string dir;
    cin >> sx >> sy >> ex >> ey >> dir;
    d=md[dir];
}

bool chk (int ax, int ay, int bx, int by)
{
    if (ay==by)
    {
        if (bx<ax) swap(bx, ax);
        for (int i=ax; i<=bx; ++i)
            if (a[i][ay] || a[i][ay+1]) return false;
        return true;
    } else
    {
        if (by<ay) swap(by, ay);
        for (int i=ay; i<=by; ++i)
            if (a[ax][i] || a[ax+1][i]) return false;
        return true;
    }
}

void Solve()
{
    for (int i=1; i<=n+1; ++i)
        for (int j=1; j<=m+1; ++j)
            s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    memset(dist, -1, sizeof dist);
    queue<pair<pair<int, int>, int> > q;
    q.push({{sx, sy}, d});
    dist[sx][sy][d]=0;
    while (!q.empty())
    {
        pair<pair<int, int>, int> top=q.front(); q.pop();
        int x=top.first.first;
        int y=top.first.second;
        int f=top.second;
        ///rotate!
        if (dist[x][y][(f+1)%4]<0)
        {
            dist[x][y][(f+1)%4]=dist[x][y][f]+1;
            q.push({{x, y}, (f+1)%4});
        }
        if (dist[x][y][(f-1+4)%4]<0)
        {
            dist[x][y][(f-1+4)%4]=dist[x][y][f]+1;
            q.push({{x, y}, (f-1+4)%4});
        }
        ///go!
        for (int steps=1; steps<=3; ++steps)
        {
            int ax=x+steps*dx[f];
            int ay=y+steps*dy[f];
            if (ax<1 || ax>=n || ay<1 || ay>=m || !chk(x, y, ax+(ax>x), ay+(ay>y))
                || dist[ax][ay][f]!=-1) continue;
            dist[ax][ay][f]=dist[x][y][f]+1;
            q.push({{ax, ay}, f});
        }
    }
    int res=1e9;
    for (int i=0; i<4; ++i)
        if (dist[ex][ey][i]!=-1)
            res=min(res, dist[ex][ey][i]);
    if (res==1e9)
        res=-1;
    cout << res << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    md["north"]=0;
    md["east"]=1;
    md["south"]=2;
    md["west"]=3;
    while (cin >> n >> m)
    {
        if (n<1 && m<1) return 0;
        Input();
        Solve();
    }
}
