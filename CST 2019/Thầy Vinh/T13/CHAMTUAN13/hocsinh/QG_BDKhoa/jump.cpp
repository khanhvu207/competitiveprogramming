#include <bits/stdc++.h>

using namespace std;

int a[1005],f[1005][1005],n;

int trye(int x, int tmp)
{
    if (x==n) return 0;
    if (f[x][tmp]!=-1) return f[x][tmp];
    int kq = 1e8;
    if (x+tmp<=n) kq = min(kq,trye(x+tmp,tmp+1) + a[x+tmp]);
    if (x-tmp+1>0 && x!=1)kq = min(kq,trye(x-tmp+1,tmp) + a[x-tmp+1]);
    f[x][tmp] = kq;
    return kq;
}

int main()
{
    freopen("jump.inp","r",stdin);
    freopen("jump.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    memset(f,-1,sizeof(f));
    cout << trye(1,1) ;
    return 0;
}
