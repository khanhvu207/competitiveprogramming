#include<bits/stdc++.h>
long long l,u,v,c,n,i,j,h,k,t,d,m,kt[200005];
using namespace std;
#define pi pair<int,long long>
#define pi2 pair<long long,pi>
vector <pi> x[200005];
priority_queue <pi2> q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("danang.inp","r",stdin);
    freopen("danang.out","w",stdout);
    cin>>n>>m>>d;
    m++;
    for(i=1;i<=n;i++) kt[i]=1e18;
    for(i=1;i<=m;i++)
    {
        cin>>u>>v>>c;
        x[u].push_back(pi(v,c));
        x[v].push_back(pi(u,c));
    }
    q.push(pi2(h,pi(1,-1e15)));
    while (q.size()!=0)
    {
        u=q.top().second.first;
        t=q.top().first;
        l=q.top().second.second;
        q.pop();
        if (l<kt[u])
        {
            kt[u]=l;
            if (u==n) {cout<<-t; return 0;}
            for(i=0;i<x[u].size();i++)
            {
                v=x[u][i].first;
                c=x[u][i].second;
                if (c>=l+d&&c<kt[v])
                {
                    q.push(pi2(t-c,pi(v,c)));
                }
            }
        }
    }
    cout<<-1;
}
