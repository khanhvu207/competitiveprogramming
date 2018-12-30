#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll a, b, k;

ll fastmul(ll a, ll k)
{
    if (k == 0) return 0;
    ll t = fastmul(a, k / 2);
    t = (t + t) % b;
    if (k & 1) return (t + a) % b;
    else return t;
}

ll fastpow(ll base, ll expo)
{
    if (!expo) return 1 % b;
    else
    {
        ll t = fastpow(base, expo / 2);
        t = fastmul(t, t) % b;
        if (expo & 1) return (fastmul(t, base % b)) % b;
        else return t % b;
    }
}



int main()
{
    freopen("DIGIT.INP", "r", stdin);
    freopen("DIGIT.OUT", "w", stdout);

    cin >> a >> b >> k;

    ll res;
    if (k == 1) res = ((a % b) * 10) / b;
    else res = (fastmul(a, fastpow(10, k - 1)) % b * 10) / b;
    cout << res;
    return 0;
}
