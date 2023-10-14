#include <bits/stdc++.h>

using namespace std;

long long n,k;

int prime[1000005];

void sang()
{
    for (int i=2;i<=1e6; i++) prime[i] = i;
    for (int i=2; i<=1e3; i++)
        if (prime[i]==i)
            for (int j=i; j<=1e6/i; j++)
                prime[i*j] = i;
}

int main()
{
    freopen("maxpow.inp","r",stdin);
    freopen("maxpow.out","w",stdout);
    int test; cin >> test;
    //sang();
    while (test--)
    {
        cin >> n >> k;
        long long kq=1e18;
        for (int i=2; i<=(int) sqrt(k); i++)
        if (k%i==0)
        {
            long long dem1 = 0;
            while (k%i==0)
            {
                k/=i;
                dem1++;
            }
            long long dem2 = 0; long double j=1;
            while (true)
            {
                j*=i;
                dem2+=(long long) n/j;
                if ((long double)n/j <1) break;
            }
            kq = min(kq,dem2/dem1);
        }

        if (k>1)
        {
            long long dem1 = 1;
            long long dem2 = 0; long double j=1;
            while (true)
            {
                j*=(long double) k;
                dem2+=(long long) n/j;
                if ((long double) n/j < 1) break;
            }
            kq = min(kq,dem2/dem1);
        }
        cout << kq << '\n';
    }
    return 0;
}
