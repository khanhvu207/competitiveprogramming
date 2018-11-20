#include <iostream>
#include <cstdio>
using namespace std;

long long n;

int main()
{
    freopen("digits.inp", "r", stdin);
    freopen("digits.out", "w", stdout);
    cin>>n;
    long long cnt=0ll;
    long long k=10ll, num=9ll, digit=1ll;
    while(n>k)
        cnt+=digit*num,
        ++digit, num*= 10ll, k*= 10ll;
    cnt+=(n-(k/10)+1)*digit;
    cout<<cnt+(n==k?1:0);
    return 0;
}
