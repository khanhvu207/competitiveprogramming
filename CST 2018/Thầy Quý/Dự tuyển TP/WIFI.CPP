#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n,a,b;
long long q[2002];
double f[2002];

int main()
{
    freopen("input.INP","r",stdin);
    //freopen(".OUT","w",stdout);

    cin >> n >> a >> b;
    for (int i = 0; i<n; i++) cin >> q[i];
    sort(q, q+n);

    for (int i = 0; i<n; i++)
    {
        f[i] = f[i-1] + a;
        for (int j = i; j>=0; j--)
            f[i] = min( f[i] , f[j-1] + a + b * (double)(q[i]-q[j])/2) ;
    }

    cout << f[n-1] << endl;

    return 0;
}
