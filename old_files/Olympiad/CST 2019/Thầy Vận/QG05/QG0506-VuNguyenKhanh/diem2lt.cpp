#include <bits/stdc++.h>

using namespace std;

int b[200005],c[200002],sl,n,nq,luu1,luu2,a[200005],maxx;

int bns(int x)
{
    int l=0; int r=sl+1;
    while (true)
    {
        int m = (l+r)/2;
        if (c[m] == x) return m;
        if (c[m] < x) l=m;
        else r=m;
        if (l==r-1) return 0;
    }
}

void xl(int x)
{
    int p=1; int kq = a[x];
    while (p+c[x]<maxx)
    {
        int hihi=a[x];
        int mag = bns(p+c[x]); int mag2 = bns(2*p+c[x]);
        if (mag!=0) hihi+=a[mag];
        if (mag2!=0) hihi+=a[mag2];
        if (nq<hihi)
        {
            nq = hihi;
            luu1 = x; luu2 = p;
        }
        p*=2;
    }

}

int main()
{
    freopen("diem2lt.inp","r",stdin);
    freopen("diem2lt.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> b[i];
        maxx=max(maxx,n);
    }
    sort(b+1,b+n+1);
    b[n+1] = b[0] = 2*1e9;
    for (int i=1; i<=n; i++)
    {
        if (b[i]==b[i-1]) continue;
        else c[++sl] = b[i];
        a[sl]++;
    }
    for (int i=1; i<=sl; i++) xl(i);
    int hihi1 = luu1;
    int hihi2 = bns(c[luu1]+luu2);
    int hihi3 = bns(c[luu1]+luu2+luu2);
    cout << nq <<'\n';
    for (int i=1; i<=a[hihi1]; i++) cout << c[hihi1] << ' ';
    for (int i=1; i<=a[hihi2]; i++) cout << c[hihi2] << ' ';
    for (int i=1; i<=a[hihi3]; i++) cout << c[hihi3] << ' ';
    return 0;
}
