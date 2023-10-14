#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct matrix { ll _00, _01, _10, _11; };

ll x, n, m, t;

ll num(ll x)
{
    ll res = 0; while (x > 0) x /= 10, res++; return res;
}

ll modmul(ll x, ll y) {
    return ((x % m) * (y % m)) % m;
}

ll fastmul(ll a, ll k)
{
    if (k == 0) return 0;
    //if (ceil(log10(a) + log10(k)) <= 15) return modmul(a, k);
    ll t = fastmul(a, k / 2ll);
    t = (t + t) % m;
    if (k & 1) return (t + a) % m;
    else return t;
}

ll fastpow(ll base, ll expo)
{
    if (!expo) return 1ll % m;
    else
    {
        ll t = fastpow(base, expo / 2);
        t =  modmul(t, t);
        if (expo & 1) return modmul(t, base);
        else return t;
    }
}

matrix Mul(const matrix &a, const matrix &b)
{
    matrix c;
    c._00 = (fastmul(a._00, b._00) + fastmul(a._01, b._10)) % m;
    c._01 = (fastmul(a._00, b._01) + fastmul(a._01, b._11)) % m;
    c._10 = (fastmul(a._10, b._00) + fastmul(a._11, b._10)) % m;
    c._11 = (fastmul(a._10, b._01) + fastmul(a._11, b._11)) % m;
    return c;
}

matrix matrixMul(matrix A, ll k)
{
    if (k <= 1) return A;
    matrix t = matrixMul(A, k / 2);
    t = Mul(t, t);
    if (k & 1) return Mul(t, A);
    else return t;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("REMAINDER.INP", "r", stdin);
    freopen("REMAINDER.OUT", "w", stdout);

    cin >> t;
    while (t--)
    {
        cin >> x >> n >> m;
        ll k = num(x);
        matrix T;
        T._00 = fastpow(10ll, k);
        T._01 = 0ll;
        T._10 = 1ll;
        T._11 = 1ll;

        T = matrixMul(T, n);
        ll res = fastmul(x, T._10);
        cout << res << '\n';
    }
    return 0;
}

