#include <iostream>
#include <cstdio>
#include <algorithm>

#define ii pair<int,int>
#define fi first
#define se second
#define maxN 100005

using namespace std;
ii a[maxN]; int n,BIT[maxN*10];

int get(int x)
{
    int res=0;
    for (; x>0; x-=x&-x) res=max(res,BIT[x]);
    return res;
}

void update(int x,int val)
{
    for (; x<=1000002; x+=x&-x) BIT[x]=max(BIT[x],val);
}

int main()
{
    freopen("machdien.inp","r",stdin);
    freopen("machdien.out","w",stdout);
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d",&a[i].fi,&a[i].se);
        a[i].fi++; a[i].se++;
    }
    sort(a+1,a+n+1);
    int res=0;
    for (int i=n; i>0; i--)
    {
        int tmp=get(a[i].se-1)+1;
        res=max(res,tmp);
        update(a[i].se,tmp);
    }
    cout<<res;
    return 0;
}
