#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const long long mod=366239;
long long n, fact[20], pow10[20];
vector<long long> a;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("sumperm.inp", "r", stdin);
    freopen("sumperm.out", "w", stdout);
    fact[0]=1ll;
    for (int i=1; i<=18; ++i)
        fact[i]=(fact[i-1]*i*1ll)%mod;
    pow10[0]=1ll;
    for (int i=1; i<=18; ++i)
        pow10[i]=(pow10[i-1]*10ll)%mod;
    while (cin >> n)
    {
        a.clear();
        while (n) a.push_back(n%10ll), n/=10ll;
        long long res=0ll;
        for (int i=0; i<(int)a.size(); ++i)
            for (int p=0; p<(int)a.size(); ++p)
                res=(res+(((pow10[p]%mod)*(a[i]%mod))%mod)*(fact[(int)a.size()-1]%mod))%mod;
        cout << res << '\n';
    }
    return 0;
}
