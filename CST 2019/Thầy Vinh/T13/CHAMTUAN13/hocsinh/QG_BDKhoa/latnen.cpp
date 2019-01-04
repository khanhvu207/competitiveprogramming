#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;

int w,h,f[700][700],n;
ii a[300];

int trye(int w, int  h)
{
    if (f[w][h]!=-1) return f[w][h];
    int kq = w*h;
    for (int i=1; i<w; i++) kq = min(kq,trye(i,h) + trye(w-i,h));
    for (int i=1; i<h; i++) kq = min(kq,trye(w,i) + trye(w,h-i));

    for (int i=1; i<=n; i++)
    {
        kq = min(kq,w*h - ((w/a[i].fi)*(h/a[i].se)*a[i].fi*a[i].se)) ;
    }
    f[w][h] = kq;
    return kq;
}

int main()
{
    freopen("latnen.inp","r",stdin);
    freopen("latnen.out","w",stdout);
    memset(f,-1,sizeof(f));
    cin >> w >> h;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i].fi >> a[i].se;
    cout << trye(w,h);
    return 0;
}
