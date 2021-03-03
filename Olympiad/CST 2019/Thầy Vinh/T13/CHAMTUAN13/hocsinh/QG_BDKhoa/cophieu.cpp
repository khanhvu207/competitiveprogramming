#include <bits/stdc++.h>
#define ii pair<long long ,long long>
#define fi first
#define se second
using namespace std;

long long  n,m;
ii a[100005];

bool kt(long long x)
{
    long long t = 0;
    for (int i=1; i<=n; i++)
    {
        if (x*a[i].fi-a[i].se > 0) t+=x*a[i].fi-a[i].se;
        if (t>=m) return true;
    }
    return false;
}

int main()
{
    freopen("cophieu.inp","r",stdin);
    freopen("cophieu.out","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i].fi >> a[i].se;
    sort(a+1,a+n+1);
    long long l=0; long long r = m;
    while (true)
    {
        int t = (l+r)/2;
        if (kt(t)) r=t;
        else l=t;
        if (l==r-1) break;
    }
    cout << r;
    return 0;
}
