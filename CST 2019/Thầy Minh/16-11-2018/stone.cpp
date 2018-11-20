#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> g[415];

int dfs (int u)
{
    vector<int> k;
    for (int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        k.push_back(-dfs(v));
    }
    if (k.size()==0) return 1;
    sort(k.begin(), k.end());
    int kq = 0; int t=0;
    for (int i=0; i<k.size(); i++)
    {
        kq += max(0,-k[i] - (kq-t));
        t++;
    }
    return kq;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("stone.inp", "r", stdin);
    freopen("stone.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        int u, v, t;
        cin >> u >> t;
        for (int j=0; j<t; ++j)
            cin >> v,
            g[u].push_back(v);
    }
    cout << dfs(1);
    return 0;
}
