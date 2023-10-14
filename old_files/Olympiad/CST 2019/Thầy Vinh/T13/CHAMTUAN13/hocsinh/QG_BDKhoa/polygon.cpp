#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<long long,long long>
using namespace std;
long long n;
ii a[100000];

int ucln(long long a, long long b)
{
    if (a==0) return b;
    if (b==0) return a;
    long long du;
    do
    {
        du = a%b;
        a= b;
        b= du;
    }while (du!=0);
    return a;
}

int xl(int x, int y)
{
    return ucln(abs(a[x].fi-a[y].fi),abs(a[x].se - a[y].se)) + 1;
}

int main()
{
    freopen("polygon.inp","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i].fi >> a[i].se;
    long long dt=0;
    a[n+1] = a[1]; int b=0;
    for (int i=1; i<=n; i++)
    {
        dt += (a[i].fi+a[i+1].fi)*(a[i].se - a[i+1].se);
        b += xl(i,i+1);
    }
    dt = abs(dt);
    b-=n;
    cout << (dt - b + 2)/2;
    return 0;
}
