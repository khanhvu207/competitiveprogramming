#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<long long,long long>
using namespace std;

long long val[300],n,m,r;
ii c[300][300];

int main()
{
    freopen("chiphi.inp","r",stdin);
    freopen("chiphi.out","w",stdout);
    cin >> n >> m >> r;
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            c[i][j] = ii(1e9,-1);

    for (int i=1; i<=n; i++) cin >> val[i];
    for (int i=1; i<=m; i++)
    {
        int u,v,k;
        cin >> u >> v >> k;
        c[u][v].fi = c[v][u].fi = min(c[u][v].fi,k + max(val[u],val[v]));
        c[u][v].se = c[v][u].se = max(val[u],val[v]);
    }
    for (int t=1;t<=2; t++)
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (c[i][j].fi > c[i][k].fi + c[k][j].fi - min(c[i][k].se,c[k][j].se))
                {
                    c[i][j].fi = c[i][k].fi + c[k][j].fi - min(c[i][k].se,c[k][j].se);
                    c[i][j].se = max(c[i][k].se,c[k][j].se);
                }

    while (r--)
    {
        int u,v;
        cin >> u >> v;
        cout << c[u][v].fi<<'\n';
    }
    return 0;
}
