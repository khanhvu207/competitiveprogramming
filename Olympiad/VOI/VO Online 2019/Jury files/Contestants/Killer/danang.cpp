#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;
const long oo=1e9+7;
vector <ii> a[200005];
long n,m,D;

void Docfile()
{
    scanf("%d%d%d",&n,&m,&D);
    int u,v,w;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back(ii(v,w));
        a[v].push_back(ii(u,w));
    }
}

long Dijsktra()
{
    int dd[200005];
    long d[200005];
    for (int i=1;i<=n;i++)
    {
        dd[i]=0;
        d[i]=oo;
    }
    priority_queue<iii,vector<iii>,greater<iii>> pq;
    pq.push(iii(ii(0,1),0));
    while (!pq.empty())
    {
        int w=pq.top().first.first,u=pq.top().first.second,re=pq.top().second;
        pq.pop();
        if (u==n)
            return d[u];
        if (dd[u])
            continue;
        dd[u]=1;
        for (int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].first,t=a[u][i].second;
            if ((t>=re+D) && (d[v]>w+t))
            {
                d[v]=w+t;
                pq.push(iii(ii(d[v],v),t));
            }
        }
    }
    return -1;
}

int main()
{
    freopen("danang.inp","r",stdin);
    freopen("danang.out","w",stdout);
    Docfile();
    printf("%d",Dijsktra());
}
