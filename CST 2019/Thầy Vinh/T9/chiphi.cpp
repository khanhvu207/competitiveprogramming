#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define int64 long long

int n, m, q;
long long c[333], w[333][333], cost[333][333];

void Input()
{
    cin >> n >> m >> q;
    for (int u=1; u<=n; ++u) cin >> c[u];
    for (int i=0, u, v; i<m; ++i)
    {
        int64 tmp;
        cin >> u >> v;
        cin >> tmp;
        if (w[u][v]==0)
            w[u][v]=tmp;
        else
            w[u][v]=min(w[u][v], tmp);
        w[v][u]=w[u][v];
    }
}

void Solve()
{
    vector<pair<int, int> > a;
    for (int i=1; i<=n; ++i)
        a.push_back({c[i], i});
    sort(a.begin(), a.end());
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
        {
            if (w[i][j]==0){
                w[i][j]=1e16;
                cost[i][j]=1e16;
            } else {
                cost[i][j]=w[i][j]+max(c[i], c[j]);
            }
        }
    for (int l=0; l<n; ++l)
    {
        int k=a[l].second;
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                if (w[i][j]>=w[i][k]+w[k][j])
                {
                    w[i][j]=w[i][k]+w[k][j];
                    if (cost[i][j]>w[i][j]+max(c[i], max(c[j], c[k])))
                        cost[i][j]=w[i][j]+max(c[i], max(c[j], c[k]));
                }
    }
    for (int u, v; q; --q)
    {
        cin >> u >> v;
        cout << cost[u][v] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("chiphi.inp", "r", stdin);
    freopen("chiphi.out", "w", stdout);
    Input();
    Solve();
}
