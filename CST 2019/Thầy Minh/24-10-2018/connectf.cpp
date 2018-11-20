#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, r[1015], p[1015];
long long sum;
vector<pair<long long, pair<int, int> > > e;
pair<int, int> pt[1015];
vector<pair<int, int> > ans;

bool joint (int u, int v)
{
    while (p[u]!=u) p[u]=p[p[u]], u=p[u];
    while (p[v]!=v) p[v]=p[p[v]], v=p[v];
    if (u==v) return false;
    if (r[u]>r[v])
        r[u]+=r[v], p[v]=u;
    else
        r[v]+=r[u], p[u]=v;
    return true;
}

int main()
{
    freopen("connectf.inp", "r", stdin);
    freopen("connectf.out", "w", stdout);
    cin>>n;
    for (int i=0, x, y; i<n; i++)
        cin>>x>>y,
        pt[i]={x, y};
    for (int i=0; i<n-1; i++)
        for (int j=i+1; j<n; j++)
        {
            long long dist=abs(pt[i].first-pt[j].first)+abs(pt[i].second-pt[j].second);
            e.push_back({dist, {i+1, j+1}});
        }
    sort(e.begin(), e.end());
    for (int i=1; i<=n; i++) r[i]=1, p[i]=i;
    for (int i=0; i<(int)e.size(); i++)
        if (joint(e[i].second.first, e[i].second.second))
            sum+=e[i].first,
            ans.push_back({e[i].second.first, e[i].second.second});
    cout<<sum<<'\n';
    sort(ans.begin(), ans.end());
    for (int i=0; i<(int)ans.size(); i++)
        cout<<ans[i].first<<' '<<ans[i].second<<'\n';
    return 0;
}
