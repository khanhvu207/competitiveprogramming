#include <iostream>
#include <cstdio>
using namespace std;

int n, a[200015], p[200015];

int main()
{
    freopen("wys.inp", "r", stdin);
    freopen("wys.out", "w", stdout);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i],
        a[i+n]=a[i];
    for (int i=1; i<=2*n; i++)
        p[i]=p[i-1]+a[i];
    int i=1, j=1;
    int res=0;
    for (int k=0; k<10000000; k++)
    {
        if (j>n) j--;
        if (i>n) break;
        res=max(res, min(p[j]-p[i-1], p[n+i-1]-p[j]));
        if (p[j]-p[i-1]<p[n+i-1]-p[j]) ++j;
            else ++i;
    }
    cout<<res;
    return 0;
}
