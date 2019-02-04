#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define nmax 510000

struct mang{
    int fi, se;
};

bool cmp(mang a, mang b){
    return a.fi >= b.fi;
}

mang a[nmax];
int n;

int main(){

    freopen("BUILDING.INP","r",stdin);
    freopen("BUILDING.OUT","r",stdin);

    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        int x; cin >> x;
        if (x < 0) a[i].se = 1; else a[i].se = 0;
        a[i].fi = abs(x);
    }
    sort(a+1, a+n+1, cmp);

    int i = 1, k = a[1].se, dem = 1, tmp = a[1].fi;
    while (i <= n)
    {
        while (i <= n && (k == a[i].se || a[i].fi >= tmp)) i++;
        if (i == n+1) break;
        dem++;
        k = a[i].se; tmp = a[i].fi;
    }

    i = 2;
    k = a[2].se;
    int ans = 1;
    tmp = a[2].fi;
    while (i <= n)
    {
        while (i <= n && (k == a[i].se || a[i].fi >= tmp)) i++;
        if (i == n+1) break;
        ans++;
        k = a[i].se; tmp = a[i].fi;
    }

    cout << max(ans, dem) << endl;
    return 0;
}
