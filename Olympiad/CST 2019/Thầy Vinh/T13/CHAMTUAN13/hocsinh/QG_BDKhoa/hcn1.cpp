#include <bits/stdc++.h>

using namespace std;

int n,m,f[506][506];

int trye(int n, int m)
{
    if (n==1) return m;
    if (m==1) return n;
    if (n==m) return 1;
    if (f[n][m]!=-1) return f[n][m];
    int kq = 1e9;
    for (int i=1; i<n; i++) kq = min(kq, trye(n-i,m) + trye(i,m));
    for (int i=1; i<m; i++) kq = min(kq, trye(n,m-i) + trye(n,i));
    f[n][m] = kq;
    return kq;
}

int main()
{
    freopen("hcn1.inp","r",stdin);
    freopen("hcn1.out","w",stdout);
    memset(f,-1,sizeof(f));
    cin >> n >> m;
    cout << trye(n,m);
    return 0;
}
