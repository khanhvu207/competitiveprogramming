#include <bits/stdc++.h>
typedef struct o_struct{long long x,y,c;}o;
using namespace std;
o c[200005];
typedef pair <long long,long long> ii;
typedef pair <ii,long long> iii;
long long m,n,d[200005],dd,x,hx,pre;
vector <long long> a[200005],w[200005];
priority_queue <ii ,vector <ii> ,greater<ii> >h;
int main()
{
    freopen("danang.inp","r",stdin);
    freopen("danang.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&dd);
    for (int i=1;i<=m;i++)
        scanf("%lld%lld%lld",&c[i].x,&c[i].y,&c[i].c);
    if (m<=1000)
    {
        for (int i=1;i<=m;i++)
        {
            c[i+m].x=c[i].y;
            c[i+m].y=c[i].x;
            c[i+m].c=c[i].c;
        }
        c[0].x=0;c[0].y=1;
        c[m*2+1].x=n;c[m*2+1].y=n+1;c[m*2+1].c=2000000005;
        for (int i=0;i<=m*2;i++)
            for (int j=1;j<=m*2+1;j++)
        if (c[i].y==c[j].x && c[i].c+dd<=c[j].c)
        {
        a[i].push_back(j);
        w[i].push_back(c[j].c);
     //   cout<<i<<' '<<j<<endl;
        }
        for (int i=1;i<=m*2+1;i++)
            d[i]=2000000000000000;
        d[0]=0;
        h.push(ii(0,0));
        while (h.size()!=0)
        {
            x=h.top().second;
            hx=h.top().first;
            h.pop();
            if (hx!=d[x]) continue;
            for (int i=0;i<a[x].size();i++)
            if (d[a[x][i]]>d[x]+w[x][i])
            {
                d[a[x][i]]=d[x]+w[x][i];
                h.push(ii(d[a[x][i]],a[x][i]));
            }
        }
        if (d[m*2+1]==2000000000000000) cout<<-1;else
        cout<<d[m*2+1]-2000000005;
    }
    else
    {
        priority_queue <iii , vector <iii> ,greater<iii> > h;
        while (h.size()!=0) h.pop();
        for (int i=1;i<=m;i++)
        {
            a[c[i].x].push_back(c[i].y);
            w[c[i].x].push_back(c[i].c);
            a[c[i].y].push_back(c[i].x);
            w[c[i].y].push_back(c[i].c);
        }
        for (int i=1;i<=n;i++)
            d[i]=2000000000000000;
        d[1]=0;
        h.push(iii(ii(0,-2000000000000000),1));
        while (h.size()!=0)
        {
            x=h.top().second;
          //  cout<<a[x].size()<<endl;
            hx=h.top().first.first;
            pre=h.top().first.second;
            h.pop();
            if (hx!=d[x]) continue;
            for (int i=0;i<a[x].size();i++)
            if (d[a[x][i]]>d[x]+w[x][i] && pre+dd<=w[x][i])
           {
                d[a[x][i]]=d[x]+w[x][i];
                h.push(iii(ii(d[a[x][i]],w[x][i]),a[x][i]));
            }
        }
        if (d[n]==2000000000000000) cout<<-1;else
        cout<<d[n];
    }
}
