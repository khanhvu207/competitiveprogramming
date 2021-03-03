#include <bits/stdc++.h>

using namespace std;

int n,m,f[300005],kq,a[300005];

int main()
{
    freopen("ninja.inp","r",stdin);
    freopen("ninja.out","w",stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=m+1; i<=n; i++)
    {
        f[i] = max(f[i-1],f[i-m]  + a[i]);
        kq = max(kq,f[i]);
    }
    cout << kq;
    return 0;
}
