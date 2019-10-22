/*
ID: khanhvu2
LANG: C++14
TASK: fact4
*/
#include <bits/stdc++.h>
using namespace std;

int n;

int zeroes(int n) {
    int cnt_2=0, cnt_5=0;
    for (int i=1; i<=n; ++i) {
        int t=i;
        while (t%2==0) ++cnt_2, t/=2;
        t=i;
        while (t%5==0) ++cnt_5, t/=5;
    }
    return min(cnt_2, cnt_5);
}

int main() {
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);
    cin>>n;
    int cnt=zeroes(n);
    int two=cnt, five=cnt;
    int res=1;
    for (int i=1; i<=n; ++i) {
        int x=i;
        while (two&&x%2==0) --two, x/=2;
        while (five&&x%5==0) --five, x/=5;
        res=(res*x)%10;
    }
    cout<<res<<'\n';
}

