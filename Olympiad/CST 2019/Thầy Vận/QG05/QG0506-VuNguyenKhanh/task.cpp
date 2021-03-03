#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m, max_time=0, h[1015], d[1015];
bool vst[1015];
vector<int> g[1015], p[1015];

void dfs (int u)
{
    vst[u]=1;
    h[u]=0;
    for (int i=0; i<(int)g[u].size(); i++)
    {
        if (!vst[g[u][i]]) dfs(g[u][i]);
        h[u]=max(h[g[u][i]], h[u]);
    }
    ++h[u];
    max_time=max(max_time, h[u]);
}

bool chk (int machine)
{
    for (int i=1; i<=n; i++) d[i]=0;
    for (int i=1; i<=n; i++) vst[i]=0;
    for (int i=1; i<=n; i++) d[i]=(int)g[i].size();
    int cnt=n, t=0;
    while (cnt>0)
    {
        int m=machine;
        vector<int> q;
        for (int i=1; i<=n; i++)
            if (d[i]<1&&!vst[i]&&m>0)
            {
                --cnt; --m;
//                cerr << i << ' ';
                q.push_back(i);
                vst[i]=1;
            }
        ++t;
        for (int i=0; i<(int)q.size(); i++)
            for (int j=0; j<(int)p[q[i]].size(); j++)
                --d[p[q[i]][j]];
//        cerr << '\n';
//        cerr << "At time:" << t << ' ' << cnt << '\n';
//        for (int i=1; i<=n; i++)
//            cerr << i << ' ' << d[i] << '\n';
    }
    return (t==max_time);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("task.inp", "r", stdin);
    freopen("task.out", "w", stdout);
    cin >> n >> m;
    for (int i=0, u, v; i<n; i++)
        cin >> u >> v,
        g[v].push_back(u),
        p[u].push_back(v);
    for (int i=1; i<=n; i++)
        if (!vst[i]) dfs(i);
    int l=1, r=n, res;
    while (l<=r)
    {
        int m=(l+r)>>1;
        if (chk(m)) r=m-1, res=m;
            else l=m+1;
    }
    cout << max_time << ' ' << res;
    return 0;
}
