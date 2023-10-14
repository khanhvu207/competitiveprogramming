#include<bits/stdc++.h>
long long n,i,j,h,k,d,m,base,p[100005],a[100005],b[100005];
using namespace std;
bool kt(long long m)
{
    int i,j,ii,jj;
    n=k/m;
    for(i=0;i<base;i++)
    {
        a[1]=i;
        for(j=1;j<=n;j++)
        {
            for(h=0;h<base;h++) if (i*h%base==p[j]) {b[j]=h;break;}
            if (h==base) break;
        }
        if (j==n+1)
        {
            for(ii=2;ii<=m;ii++)
            {
            for(h=0;h<base;h++)
            {
                for(jj=1;jj<=n;jj++) if (h*b[jj]%base!=p[(ii-1)*n+jj]) jj=n+2;
                if (jj==n+1) {a[ii]=h;break;}
            }
            if (h==base) break;
            }
            if (ii==m+1)
            {
                cout<<m<<' ';
                for(jj=1;jj<=m;jj++) cout<<a[jj]<<' ';cout<<endl;
                cout<<n<<' ';
                for(jj=1;jj<=n;jj++) cout<<b[jj]<<' ';
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("wedding.inp","r",stdin);
    freopen("wedding.out","w",stdout);
    cin>>k>>base;
    for(i=1;i<=k;i++) cin>>p[i];

    if (base<=7) for(i=2;i<=sqrt(k);i++) if (k%i==0&&(kt(i)||kt(k/i))) return 0;
    cout<<"NO";
}
