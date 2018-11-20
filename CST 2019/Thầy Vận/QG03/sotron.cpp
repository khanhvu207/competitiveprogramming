#include <iostream>
#include <cstdio>
using namespace std;

long long n;

int main()
{
    freopen("sotron.inp", "r", stdin);
    freopen("sotron.out", "w", stdout);
    cin>>n;
    if (n==1)
    {
        cout<<0;
        return 0;
    }
    n--;
    int len=35;
    while (!(n&(1ll<<len))) --len;
    for (long long i=len; i>=0; i--)
        cout<<((n&(1ll<<i))?5:0);
    return 0;
}
