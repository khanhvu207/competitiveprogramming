#include <bits/stdc++.h>

using namespace std;

const long mod=998244353;
int a[22],n,d,t;
long res=0;
int sum[3]={0,-1,1};

void Check()
{
    int gtmax,gtmin,dem;
    dem=0;
    for (int i=0;i<=n-d+1;i++)
    {
        gtmax=a[i];
        gtmin=a[i];
        for (int j=i+1;j<=i+d-1;j++)
        {
            gtmax=max(gtmax,a[j]);
            gtmin=min(gtmin,a[j]);
        }
        if (gtmax-gtmin<=1)
            dem++;
    }
    if (dem==t)
        res++;
}

void Try(int i)
{
    if (i==n+1)
        Check();
    else
        for (int j=1;j<=2;j++)
        {
            a[i]=a[i-1]+sum[j];
            Try(i+1);
        }
}

void Xuli()
{
    scanf("%d%d%d",&n,&d,&t);
    a[0]=0;
    Try(1);
    printf("%d",res%mod);
}

int main()
{
    freopen("singer.inp","r",stdin);
    freopen("singer.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Xuli();
}
