#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[30000], ans[30000], h[30000];
vector<int> a[30000];
bool blank[30000], fre[30000];
int n,m,s,t;

void dfs(int u, int i)
{
    x[i] = u;
    if (u == t)
    {
        for (int j = 1; j<=i; j++)
        {
            ans[j] = x[j];
            h[ans[j]] = 1;
            blank[ans[j]] = false;
        }
        m = i;
        return;
    }

    fre[u] = false;
    for (ll v = 0; v < a[u].size(); v++)
        if (fre[a[u][v]])
                dfs(a[u][v], i+1);
}

int dfs2(int u)
{
    int re = 0;
    fre[u] = false;
    for (int i = 0; i < a[u].size(); i++)
        if (fre[a[u][i]])
            re = max(re, dfs2(a[u][i]));
    return re+1;
}

int main()
{
    freopen("wedding.inp","r",stdin);
    freopen("wedding.out","w",stdout);
    cin >> n;
    for (int i = 1; i<n; i++)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cin >> s >> t;

    memset(fre,true,sizeof(fre));
    memset(blank,true,sizeof(blank));
    dfs(s,1);

    memset(fre,true,sizeof(fre));
    for (int i = 1; i<=m; i++)
    {
        fre[ans[i]] = false;
        for (int j = 0; j < a[ans[i]].size(); j++)
            if (fre[a[ans[i]][j]] && blank[a[ans[i]][j]])
                h[ans[i]] = max( h[ans[i]] , dfs2(a[ans[i]][j])+1 );
    }

    int smax = 0;
    for (int i = 1; i < m; i++)
        for (int j = i+1; j <= m; j++)
            smax = max( smax , min(h[i]+i-1 , h[j]+m-j) );

    cout << smax << endl;
    return 0;
}
