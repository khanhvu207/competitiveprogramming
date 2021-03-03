#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, k;
long long fact[100001];
const long long mod = 1000000007;

long long fastpow (long long base, long long expo)
{
    if (expo<1) return 1ll;
    long long t=fastpow(base, expo/2)%mod;
    t=(t*t)%mod;
    if (expo&1) return (t*(base%mod))%mod;
    return t;
}

long long P (int n, int k)
{
    long long base=fact[n-k]%mod;
    base=fastpow(base, mod-2)%mod;
    return ((fact[n]%mod)*base)%mod;
}

int main()
{
    freopen("demhv.inp", "r", stdin);
    freopen("demhv.out", "w,", stdout);
    fact[0]=1ll;
    for (int i=1; i<=100000; i++) fact[i]=(fact[i-1]*i*1ll)%mod;
    while (cin>>n>>k)
    {
        long long res=0ll;
        for (int i=1; i<=n; i++)
        {
            int l=1, r=n, cnt=0, t=-1;
            while (l<=r)
            {
                int m=(l+r+1)/2;
                ++t;
                if (i==m) break;
                if (i<m) r=m-1;
                    else l=m+1, ++cnt;
            }
            if (t-cnt>n-k||cnt>k-1) continue;
            res=(res+((P(n-k, t-cnt)*P(k-1, cnt))%mod)*(fact[n-t-1]%mod))%mod;
        }
        cout<<res<<'\n';
    }
    return 0;
}
