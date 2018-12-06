#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int n, q, root, timer=0;
bool ball[100015];
int p[25][100015], r[100015], h[100015];
pair<int, int> info[100015];
vector<int> g[100015];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap;

void Input()
{
    memset(p, -1, sizeof p);
    cin >> n >> q;
    for (int i=1, x; i<=n; ++i)
    {
        cin >> x;
        g[x].push_back(i);
        p[0][i]=x;
    }
}

void dfs(int u)
{
    r[u]=u;
    for (int i=0; i<(int)g[u].size(); ++i)
    {
        h[g[u][i]]=h[u]+1;
        dfs(g[u][i]);
        r[u]=min(r[u], r[g[u][i]]);
    }
}

void enqueue(int u)
{
    vector<pair<int, int> > a;
    for (int i=0; i<(int)g[u].size(); ++i)
        a.push_back({r[g[u][i]], g[u][i]});
    sort(a.begin(), a.end());
    for (int i=0; i<(int)a.size(); ++i)
        enqueue(a[i].second);
    heap.push({++timer, u});
    info[u]={timer, u};
}

void Solve()
{
    h[0]=0;
    dfs(0);
    enqueue(0);
    for (int i=1; (1<<i)<=n; ++i)
        for (int u=1; u<=n; ++u)
            if (p[i-1][u]!=-1)
                p[i][u]=p[i-1][p[i-1][u]];
    for (; q; --q)
    {
        int t, x;
        cin >> t >> x;
        if (t==1)
        {
            for (int i=0; i<x; ++i)
            {
                if (i==x-1) cout << heap.top().second << '\n';
                 ball[heap.top().second]=true;
                heap.pop();
            }
        } else
        {
            int u=x;
            for (int i=log2(h[u]); i>=0; --i)
                if (p[i][x]!=-1 && ball[p[i][x]]) x=p[i][x];
            ball[x]=false;
            heap.push(info[x]);
            cout << h[u]-h[x] << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("ball.inp", "r", stdin);
    freopen("ball.out", "w", stdout);
    Input();
    Solve();
}
