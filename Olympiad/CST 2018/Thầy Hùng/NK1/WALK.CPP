#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("WALK.INP", "r", stdin);
    freopen("WALK.OUT", "w", stdout);
    ll n, r, ans = 0;
    int a[30000];

    cin >> n >> r;
    for (ll i = 0; i<n; i++)cin >> a[i];
    for (ll i = 0; i<n; i++)
        ans += n - (upper_bound(a, a+n, a[i]+r) - a);

    cout << ans << endl;
    return 0;
}
