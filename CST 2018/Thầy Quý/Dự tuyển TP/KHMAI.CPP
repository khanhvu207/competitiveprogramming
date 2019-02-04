#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int n;
ll s,a[40];
vector<ll> x, y;

void tinh(int n, vector<ll> &x, int c)
{
    for (ll i = 0; i < (1 << n); i++)
    {
        ll tmp = 0;
        for (int j = 0; j < n; j++)
            if (i & (1 << j)) tmp += a[j+c];
        x.push_back(tmp);
    }
}

int BS(ll q)
{
    int l=0, r=y.size()-1, res=-1;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if (y[mid]<=q)
        {
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("khuyenmai.inp","r",stdin);
    freopen("khuyenmai.out","w",stdout);

    cin >> n >> s;
    for (int i = 0; i<n; i++) cin >> a[i];

    tinh(n/2, x, 0);
    tinh(n-n/2, y, n/2);

    int sx = 1 << (n/2), sy = 1 << (n-n/2);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    ll dem = 0;
    for (int i = 0; i < sx; i++)
    {
        if (x[i] > s) break;
        int p = BS(s-x[i]);
        dem += 1LL*(p+1);
    }

    cout << dem;
    return 0;
}