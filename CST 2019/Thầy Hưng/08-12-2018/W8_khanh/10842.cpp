#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int> > Edges;

int n, m, q, res;
int r[111], p[111];
vector<Edges> a;

void Input()
{
    a.clear();
    cin >> n >> m;
    for (int i=0, u, v, c; i<m; ++i)
        cin >> u >> v >> c,
        a.push_back({c, {u, v}});
}

bool joint(int u, int v)
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

int Solve()
{
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i=0; i<=n; ++i)
        r[i]=1, p[i]=i;
    res=2e9;
    for (int i=0; i<(int)a.size(); ++i)
        if (joint(a[i].second.first, a[i].second.second))
            res=min(res, a[i].first);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("10842.inp", "r", stdin);
    freopen("10842.out", "w", stdout);
    cin >> q;
    for (int i=1; i<=q; ++i)
    {
        Input();
        cout << "Case #" << i << ": " << Solve() << '\n';
    }
}
