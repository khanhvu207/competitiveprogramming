#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 5000001

int const value[3]={1,2,5};

int n,Q;
long long a,m,p,d[maxn],f[maxn],c[5][maxn];

void update(long long d[],int p,long long value)
{
    for(; p<maxn ;p+=p&(-p)) d[p]+=value;
}

void update(long long d[],int a,int b,long long value)
{
    update(d,a,value); update(d,b+1,-value);
}

long long get(long long d[],int p)
{
    long long res=0;
    for(; p>0 ;p-=p&(-p)) res+=d[p];
    return res;
}

int Find(long long x)
{
    long long l=1,r=m;
    while(l < r)
    {
        long long m=(l+r)/2,
        ss=get(f,m);
        if (m-ss < x) l=m+1; else r=m;
    }
    if (l-get(f,l) == x) return l;
    if (r-get(f,r) == x) return r;
    return -1;
}

int main()
{
    freopen("FIRES.INP","r",stdin);
    freopen("FIRES.OUT","w",stdout);
    scanf("%d",&n); m=0;
    for(int i=1; i<=3 ;i++)
        for(int j=1; j<=n ;j++)
        {
            scanf("%lld",&c[i][j]); p=0;
            for(int k=1; k<i ;k++) p+=c[k][j];
            update(d,p+1,p+c[i][j],value[i-1]);
            m=max(m,p+c[i][j]);
        }
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%lld",&a);
        a=Find(a);
        if (a == -1) {printf("0\n"); continue;}
        update(f,a,1);
        printf("%lld\n",get(d,a));
    }
    return 0;
}
