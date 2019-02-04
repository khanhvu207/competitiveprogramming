#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    freopen("capso.inp","r",stdin);
    freopen("capso.out","w",stdout);

    int n; cin >> n;
    int a[n+1], b[n+1];
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    sort(a+1,a+n+1); sort(b+1,b+n+1);

    long long d[n+1];
    d[0] = 0;
    if (a[1] == b[1]) d[1] = 1000000000000000; else d[1] = abs(a[1] - b[1]);
    for (int i = 2; i <= n; i++)
    {
        d[i] = 1000000000000000;
        if (a[i] != b[i]) d[i] = d[i-1] + abs(a[i] - b[i]);
        d[i] = min(d[i] , d[i-2] + abs(a[i-1] - b[i]) + abs(a[i] - b[i-1]));
        if (i > 2){
            long long qa = 1000000000000000;
            for (int q = i; q >= i-2; q--)
                for (int w = i; w >= i-2; w--)
                    for (int e = i; e >= i-2; e--)
                        if (q != w && w != e && q != e && a[i] != b[q] && a[i-1] != b[w] && a[i-2] != b[e])
                            if (qa > abs(a[i]-b[q]) + abs(a[i-1]-b[w]) + abs(a[i-2]-b[e]))
                                qa = abs(a[i]-b[q]) + abs(a[i-1]-b[w]) + abs(a[i-2]-b[e]);
            if (d[i] > d[i-3] + qa) d[i] = d[i-3] + qa;
        }
    }

    cout << d[n];
    return 0;
}
