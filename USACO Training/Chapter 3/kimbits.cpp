/*
ID: khanhvu2
LANG: C++14
TASK: kimbits
*/
#include <bits/stdc++.h>
using namespace std;

int n, l;
long long k, f[32][32];

long long go(int i, int cnt) {
    if (i==n) {
        f[i][cnt]=cnt<=l;
        return f[i][cnt];
    }
    long long& res=f[i][cnt];
    if (res!=-1) return res;
    res=go(i+1, cnt)+go(i+1, cnt+1);
    return res;
}

void _print(int i, int cnt) {
    if (i==n) return;
    if (f[i+1][cnt]>=k) {
        cout<<0;
        _print(i+1, cnt);
    }
    else {
        k-=f[i+1][cnt];
        cout<<1;
        _print(i+1, cnt+1);
    }
}

int main() {
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);
    cin>>n>>l>>k;
    memset(f, -1, sizeof f);
    go(0, 0);
    _print(0, 0);
    cout<<'\n';
    return 0;
}
