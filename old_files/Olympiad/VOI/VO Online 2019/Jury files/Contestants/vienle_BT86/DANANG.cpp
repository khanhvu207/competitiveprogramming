#include <bits/stdc++.h>
#define N 200005
#define fi first
#define sc second
#define oo 1000000000000000000

using namespace std;

typedef long long ll;
typedef pair<ll,int> ii;
struct data{
    int v; ll w, s;
};

vector<ii> g[N];
int n, m;
ll D, d[N];

struct cmp{
    bool operator() (data a, data b){return a.s>b.s;}
};
void dijkstra(int u)
{
    priority_queue < data, vector<data>, cmp > pq;
    for(int i=2; i<=n; ++i) d[i]=oo;
    pq.push({u,-oo,0}); d[u]=0;
    ll du, pre;

    while(pq.size())
    {
        u=pq.top().v; du=pq.top().s;
        pre=pq.top().w; pq.pop();
        if(du!=d[u]) continue;
        if(u==n) return;
        for(auto v : g[u])
            if(d[v.sc]>du+v.fi && v.fi>=pre+D)
            {
                d[v.sc]=du+v.fi;
                pq.push({v.sc,v.fi,d[v.sc]});
            }
    }
}

int main()
{
    freopen("DANANG.INP","r",stdin);
    freopen("DANANG.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m>>D;
    for(int i=1; i<=m; ++i)
    {
        int u, v; ll w;
        cin>>u>>v>>w;
        g[u].push_back(ii(w,v));
        g[v].push_back(ii(w,u));
    }
    dijkstra(1);
    if(d[n]!=oo) cout<<d[n];
    else cout<<"-1";
    return 0;
}
