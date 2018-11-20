#include <iostream>
#include <cstdio>
using namespace std;

int n, a[1000015];

bool chk (int x)
{
    for (int i=1; i<=n; ++i)
    {
        int y=a[i-1]-x;
        if (y<0||y>a[i]) return false;
        x=y;
    }
    return true;
}

int main()
{
    freopen("dayso.inp", "r", stdin);
    freopen("dayso.out", "w", stdout);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    a[n]=1e9;
    int res=0, kl=0, kr=0;
    int l=max(0, a[0]-a[1]), r=a[0];
    while (l<=r)
    {
        int m=(l+r)>>1;
        if (chk(m)) kl=m, r=m-1;
            else l=m+1;
    }
    l=kl, r=a[0];
    while (l<=r)
    {
        int m=(l+r)>>1;
        if (chk(m)) kr=m, l=m+1;
            else r=m-1;
    }
    if (kr==kl&&!chk(kl))
    {
        cout << 0;
        return 0;
    }
    res=kr-kl+1;
    cout << res;
    return 0;
}
