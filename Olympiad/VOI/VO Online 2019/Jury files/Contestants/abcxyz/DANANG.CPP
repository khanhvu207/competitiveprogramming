#include <bits/stdc++.h>
using namespace std;
struct TP
{
    int v; long long w; int prw;
};

struct cmp
{
    bool operator() (TP a,TP b) {return a.w>b.w;}
};
vector <TP> g[1000001];
TP t,uu;
int n,m,u,v,prw; long long D,oo,w,d[1000001];
priority_queue <TP,vector <TP>, cmp > H;
int main()
{
    ios_base::sync_with_stdio(false);
    freopen("DANANG.INP","r",stdin);
    freopen("DANANG.OUT","w",stdout);
    cin>>n>>m>>D;
    oo=1e9;
    for (int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        t.v=v; t.w=w;
        g[u].push_back(t);
        t.v=u;
        g[v].push_back(t);
    }
    for (int i=0;i<=n;i++) d[i]=oo;
    d[1]=0;
    t.v=1;t.w=0; t.prw=-D;
    H.push(t);
    while (!H.empty())
    {
        uu=H.top();
        H.pop();
        u=uu.v;
        prw=uu.prw;
        if (uu.w!=d[u]) continue;
        for (int i=0;i<g[u].size();i++)
        {
            v=g[u][i].v;
            w=g[u][i].w;
            if (d[v]>d[u]+w)
                if (prw+D<=w)
                {
                    d[v]=d[u]+w;
                    t.v=v; t.w=d[v]; t.prw=w;
                    H.push(t);
                }
        }
    }
    if (d[n]==1e9) cout<<-1;
    else cout<<d[n];
    return 0;
}
