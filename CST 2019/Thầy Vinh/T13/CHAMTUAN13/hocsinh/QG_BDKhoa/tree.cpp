#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
ii f[100005][4];
vector <int> a[100005];
int n,kq;
bool fre[100005];

void dfs(int u)
{
    ii haha[4];
    for (int i=0; i<a[u].size(); i++)
    {
        int v = a[u][i];
        if (fre[v])
        {
            fre[v] = false;
            dfs(v);
            haha[1] = f[u][1];
            haha[2] = f[u][2];
            haha[3] = f[v][1]; haha[3].se = v;
            sort(haha+1,haha+4);
            f[u][1] = haha[3]; f[u][2] = haha[2];
        }
    }
    f[u][1].fi++; f[u][2].fi++;
    if (f[u][1].se == 0) f[u][1].se = u;
    if (f[u][2].se == 0) f[u][2].se = u;
}

void sol(int u, int s)
{
    int tmp = s;
    if (tmp>kq) return;
    for (int i=0; i<a[u].size(); i++)
    {
        int v = a[u][i];
        if (!fre[v]) continue;
        tmp = max(tmp,f[v][1].fi);
    }
    kq = min(kq,tmp);
    for (int i=0; i<a[u].size(); i++)
    {
        int v = a[u][i];
        if (!fre[v]) continue;
        fre[v] = false;
        if (v==f[u][1].se) sol(v,max(s+1,f[u][2].fi));
        else sol(v,max(s+1,f[u][1].fi));
    }
}

int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    int test; cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i=0; i<=n; i++)
        {
            fre[i] = true;
            a[i].clear();
            f[i][1] = f[i][2] = ii(0,0);
        }

        for (int i=1; i<=n-1; i++)
        {
            int u,v;
            cin >> u >> v; u++; v++;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        kq = 1e9;
        fre[1] = false;
        dfs(1);
        for (int i=0; i<=n; i++) fre[i] = true;
        fre[1] = false;
        sol(1,0);
        cout << kq << '\n';
    }
    return 0;
}
