#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

long long n, m, a[1005][1005], q, h[1005], l[1005], r[1005], dp[1005][1005];

int main()
{
    freopen("numtab.inp", "r", stdin);
    freopen("numtab.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            scanf("%d", &a[i][j]);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            if (a[i][j]==2) h[j]=0; else h[j]++;
        h[0]=-1;
        h[m+1]=-1;
        for (int j=1; j<=m; j++)
        {
            l[j]=j;
            while (h[l[j]-1]>=h[j]) l[j]=l[l[j]-1];
        }
        for (int j=m; j>=1; j--)
        {
            r[j]=j;
            while (h[r[j]+1]>=h[j]) r[j]=r[r[j]+1];
        }
        long long res = 0ll, pos = 0;
        for (int j=1; j<=m; j++)
            if (h[j]*(r[j]-l[j]+1)>res)
                res=h[j]*(r[j]-l[j]+1), pos=j;
            else if (h[j]*(r[j]-l[j]+1)==res&&h[j]>h[pos]) pos=j;
        long long curh=1, L=l[pos], R=r[pos], sum=R-L+1;
        for (int j=i; j>=1; j--)
        {
            dp[j][i]=max(dp[j][i], curh*sum);
            curh++;
            if (curh>h[pos]) break;
        }
    }
    memset(h, 0, sizeof h);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            if (a[i][j]==0) h[j]=0; else h[j]++;
        h[0]=-1;
        h[m+1]=-1;
        for (int j=1; j<=m; j++)
        {
            l[j]=j;
            while (h[l[j]-1]>=h[j]) l[j]=l[l[j]-1];
        }
        for (int j=m; j>=1; j--)
        {
            r[j]=j;
            while (h[r[j]+1]>=h[j]) r[j]=r[r[j]+1];
        }
        long long res = 0ll, pos = 0;
        for (int j=1; j<=m; j++)
            if (h[j]*(r[j]-l[j]+1)>res)
                res=h[j]*(r[j]-l[j]+1), pos=j;
            else if (h[j]*(r[j]-l[j]+1)==res&&h[j]>h[pos]) pos=j;
        long long curh=1, L=l[pos], R=r[pos], sum=R-L+1;
        for (int j=i; j>=1; j--)
        {
            dp[j][i]=max(dp[j][i], curh*sum);
            curh++;
            if (curh>h[pos]) break;
        }
    }
    scanf("%d", &q);
    while (q--)
    {
        int l, r;
        cin>>l>>r;
        cout<<dp[l][r]<<'\n';
    }
    return 0;
}
