#include <bits/stdc++.h>
using namespace std;
long long k,base,c[2000005],s[2000005],kt,n,m,dp[2005],b[2005],a[2005],p[2005];
void alibotti(int i)
{
    for (int j=0;j<base;j++)
    if (dp[j]==0)
    {
        b[i]=j;
      //  cout<<i<<endl;
        if (i==m)
        {
            kt=0;
//            for (int z=1;z<=n;z++)
//                    printf("%lld ",a[z]);
//                    cout<<endl;
//                     for (int z=1;z<=m;z++)
//                    printf("%lld ",b[z]);
//                    cout<<endl;
            for (int z=1;z<=n;z++)
                for (int k=1;k<=m;k++)
                if ((a[z]*b[k]-c[(z-1)*m+k])%base!=0)kt=1;
            if (kt==0)
            {
                printf("YES\n");
                printf("%lld ",n);
                for (int z=1;z<=n;z++)
                    printf("%lld ",a[z]);
                    printf("\n");
                    printf("%lld ",m);
                for (int z=1;z<=m;z++)
                    printf("%lld ",b[z]);
                    exit(0);
            }
        }
        else alibotti(i+1);
    }
}
void alibotto(int i)
{
    for (int j=0;j<base;j++)
        if (p[j]==0)
    {
        a[i]=j;
        if (i==n)
            alibotti(1);
        else alibotto(i+1);
    }
}
int main()
{
    freopen("wedding.inp","r",stdin);
    freopen("wedding.out","w",stdout);
    scanf("%lld%lld",&k,&base);
    for (int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        s[i]+=s[i-1]+c[i];
    }
//    if (base==2)
//    {
//
//    }
//    else
    {
        for (int i=2;i<k;i++)
        if (k%i==0)
        {
            n=i;m=k/i;
      //     cout<<n<<' '<<m<<endl;
            alibotto(1);
        }
        cout<<"NO";
    }
}
