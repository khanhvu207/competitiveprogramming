#include <iostream>
#include <cstdio>
using namespace std;
int a, b;

int calc (int x)
{
    int watt=0;
    if (x>=2*100) watt+=100, x-=2*100;
        else watt+=(x/2), x=0;
    if (x<1) return watt;
    if (x>=3*9900) watt+=9900, x-=3*9900;
        else watt+=(x/3), x=0;
    if (x<1) return watt;
    if (x>=5*990000) watt+=990000, x-=5*990000;
        else watt+=(x/5), x=0;
    watt+=(x/7);
    return watt;
}

int pay (int watt)
{
    int money=0;
    if (watt>=100) watt-=100, money+=2*100;
        else money+=2*watt, watt=0;
    if (watt<1) return money;
    if (watt>=9900) watt-=9900, money+=3*9900;
        else money+=3*watt, watt=0;
    if (watt<1) return money;
    if (watt>=990000) watt-=990000, money+=5*990000;
        else money+=5*watt, watt=0;
    money+=7*watt;
    return money;
}

int main()
{
    freopen("12190.inp", "r", stdin);
    freopen("12190.out", "w", stdout);
    while (cin >> a >> b)
    {
        if (a<1&&b<1) return 0;
        int total=calc(a);
        int l=0, r=total/2;
        while (l<=r)
        {
            int m=(l+r)>>1;
            if (pay(total-m)-pay(m)>b) l=m+1;
                else r=m-1;
        }
        //cout << pay(150);
        cout << pay(l) << '\n';
    }
}
