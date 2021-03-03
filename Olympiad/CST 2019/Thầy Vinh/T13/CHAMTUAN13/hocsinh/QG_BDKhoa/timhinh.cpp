#include <bits/stdc++.h>

using namespace std;

int n,a[1005][1005];

int main()
{

    freopen("timhinh.inp","r",stdin);
    freopen("timhinh.out","w",stdout);
    cin >> n;
    long long kq=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            cin >> a[i][j];
            if (a[i][j]==1)
            a[i][j] += min(a[i-1][j-1],min(a[i][j-1],a[i-1][j]));
            kq = max(kq,(long long) a[i][j]);
        }

    long long dem=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (a[i][j]==kq) dem++;

    cout << dem*kq;
//    for (int i=1; i<=n; i++)
//    {
//        for (int j=1; j<=n; j++)
//            cout << a[i][j] << " ";
//        cout << '\n';
//    }
    return 0;
}
