#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

typedef long long ll;

ll a[maxn], b[maxn], MOD, k, p[maxn];

bool init(int n)
{
    int m = k/n;
    for(int i=0;i<n;i++) a[i] = -1;
    for(int i=0;i<m;i++) b[i] = -1;


    for(int i=0;i<n;i++)
    {
        int dem = 0;
        for(int j=0;j<m;j++)
        {
            dem = dem + (p[i * m + j] == 0);
        }
        if(dem == m) a[i] = 0;
    }

    for(int i=0;i<m;i++)
    {
        int dem = 0;
        for(int j=0;j<n;j++)
        {
            dem = dem + (p[j * m + i] == 0);
        }
        if(dem == m) b[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(p[i * m + j] == 0)
            {
                if(a[i] && b[j]) return false;
            }
        }
    }

    return true;
}

ll mu(ll cs, ll sm)
{
    if(sm == 0) return 1;

    ll m = mu(cs, sm/2);

    if(sm % 2 == 0) return m * m % MOD;
    else return (m * m % MOD) * cs % MOD;
}

bool add(int n, int m, int pos)
{
    for(int j=pos+1;j<n;j++)
    {
        if(a[j] == 0) continue;
        ll cur = -1;

        for(int c=0;c<m;c++)
        {
            if(b[c] == 0) continue;

            ll x = (mu(b[c], MOD - 2) * p[j * m + c]) % MOD;
            if(cur == -1) cur = x;
            else if(cur != x) return false;
        }

        a[j] = cur;
    }
    return true;
}

bool check(int n)
{
    int m = k/n;

    int pos = -1;

    for(int i=0;i<n;i++)
    {
        if(a[i] != 0)
        {
            pos = i;
            break;
        }
    }

    if(pos == -1) return true;

    for(int i=1;i<MOD;i++)
    {
        a[pos] = i;

        for(int j=0;j<m;j++)
        {
            if(b[j] == 0) continue;
            b[j] = (p[pos * m + j] * mu(a[pos], MOD - 2)) % MOD;
        }

        if(add(n, m, pos)) return true;
    }

    return false;
}

void xuat(int n)
{
    int m = k/n;

    cout << "YES" << endl;

    cout << n << " ";
    for(int i=0;i<n;i++) cout << a[i] << " ";cout << endl;
    cout << m << " ";
    for(int i=0;i<m;i++) cout << b[i] << " ";cout << endl;
}

bool solve(int n)
{
    if(!init(n)) return false;
    if(check(n))
    {
        xuat(n);
        return true;
    }
    else return false;
}

int main()
{
    freopen("WEDDING.inp","r",stdin);
    freopen("WEDDING.out","w",stdout);

    cin >> k >> MOD;

    for(int i=0;i<k;i++) cin >> p[i];

    for(int i=2;i<=sqrt(k);i++)
    {
        if(k % i == 0)
        {
            if(solve(i)) return 0;
            if(solve(k/i)) return 0;
        }
    }
    cout << "NO";
}
