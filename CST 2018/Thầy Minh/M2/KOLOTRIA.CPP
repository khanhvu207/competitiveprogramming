#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long ll;

int main()
{
    freopen("KOLOTRIA.INP", "r", stdin);
    freopen("KOLOTRIA.OUT", "w", stdout);

    ll n,m,f[11000];

    cin >> n >> m;
    memset(f,0,sizeof(f));
    for (ll i = 1; i <= m; i++)
    {
        ll x,y;
        cin >> x >> y;
        f[x]++; f[y]++;
    }

    ll ans = 0;
    for (ll i = 1; i<=n; i++)
        ans += f[i] * (n-1-f[i]);

    cout << n*(n-1)*(n-2)/6 - ans/2 << endl;
    return 0;
}
