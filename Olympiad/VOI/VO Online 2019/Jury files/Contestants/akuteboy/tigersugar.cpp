#include<bits/stdc++.h>
long long xx,y2,tt,l,r,n,i,j,h,k,t,d,m,x[100005][2],y[100005][2],a,b,res,ress;
using namespace std;
long long kt(long long t)
{
    long long res=0;
    for(i=1;i<=n;i++)
    {
        if (t>x[i][1]) res+=t-x[i][1]; else
        if (t<x[i][0]) res+=x[i][0]-t;
    }
    return res;
}
long long ktt(long long t)
{
    long long res=0;
    for(i=1;i<=n;i++)
    {
        if (t>y[i][1]) res+=t-y[i][1]; else
        if (t<y[i][0]) res+=y[i][0]-t;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("tigersugar.inp","r",stdin);
    freopen("tigersugar.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++) cin>>x[i][0]>>y[i][0]>>x[i][1]>>y[i][1];
     l=0;r=1e13;res=1e18;
     while (l+1<r)
    {
        t=(l+r)/2;
        a=kt(l);
        b=kt(r);
        if (a>b)
        {
            if (res>b) res=b,xx=r;
            l=t;
        }
        else
        if (b>a)
        {
            if (res>a) res=a,xx=l;
            r=t;
        }
        else
        {
            d=kt(t);
            if (res>d) res=d,xx=t;
            break;
        }
    }
    d=kt(r);
    if (res>d) res=d,xx=r;
    d=kt(l);
    if (res>d) res=d,xx=l;
    l=0;r=1e13;ress=1e18;
     while (l+1<r)
    {
        t=(l+r)/2;
        a=ktt(l);
        b=ktt(r);
        if (a>b)
        {
            if (ress>b) ress=b,y2=r;
            l=t;
        }
        else
        if (b>a)
        {
            if (ress>a) ress=a,y2=l;
            r=t;
        }
        else
        {
            d=ktt(t);
            if (ress>d) ress=d,y2=t;
            break;
        }
    }
    d=ktt(r);
    if (ress>d) ress=d,y2=r;
    d=ktt(l);
    if (ress>d) ress=d,y2=l;
    cout<<res+ress<<"\n";
    cout<<xx<<' '<<y2<<"\n";
    for(i=1;i<=n;i++)
    {
        if (x[i][0]>xx) cout<<x[i][0]<<' ';
        else if (x[i][1]<xx) cout<<x[i][1]<<' '; else cout<<xx<<' ';
        if (y[i][0]>y2) cout<<y[i][0]<<"\n";
        else if (y[i][1]<y2) cout<<y[i][1]<<"\n"; else cout<<y2<<"\n";
    }
}
