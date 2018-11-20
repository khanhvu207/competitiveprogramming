#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int n, m, a[215][215], row[215], col[215];
map<int, int> c;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("lamps.inp", "r", stdin);
    freopen("lamps.out", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) a[i][j]=-1;
    int x, y;
    while (cin >> x >> y)
    {
        a[x][y]=0,
        ++row[x],
        ++col[y];
    }
    int color=0;
    for (int i=1; i<=n; ++i)
        color=max(color, row[i]);
    for (int i=1; i<=m; ++i)
        color=max(color, col[i]);
    for (int i=1-m; i<=n-1; ++i)
        c[i]=(i+color*color)%color+1;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            if (a[i][j]!=-1)
                cout << i << ' ' << j << ' ' << c[i-j] << '\n';
}

