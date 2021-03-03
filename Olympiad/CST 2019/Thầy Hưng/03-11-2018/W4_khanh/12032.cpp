#include <iostream>
#include <cstdio>
using namespace std;

int t, n, a[100015];

bool chk (int x)
{
    for (int i=0; i<n; i++)
    {
        int jump=a[i]-(i<1?0:a[i-1]);
        if (jump>x) return false;
        if (jump==x)
            --x;
    }
    return true;
}

int main()
{
    freopen("12032.inp", "r", stdin);
    freopen("12032.out", "w", stdout);
    cin >> t;
    int C=0;
    while (t--)
    {
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];
        int l=1, r=10000000, res=0;
        while (l<=r)
        {
            int m=(l+r)>>1;
            if (chk(m)) r=m-1, res=m;
                else l=m+1;
        }
        cout << "Case " << ++C << ": " << res << '\n';
    }
    return 0;
}
