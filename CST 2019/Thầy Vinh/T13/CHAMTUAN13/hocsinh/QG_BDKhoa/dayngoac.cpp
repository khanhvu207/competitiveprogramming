#include <bits/stdc++.h>

using namespace std;

string st;
int f[505][505];

int trye(int l, int r)
{
    if (l==r) return 1;
    if (l>r) return 0;
    if (f[l][r]!=-1) return f[l][r];
    int kq = trye(l,l) + trye(l+1,r);
    if (st[l]=='(' || st[l] == '{' || st[l]=='[')
    {
        for (int i=l+1; i<=r; i++)
            if ( (st[l]=='(' && st[i]==')') || (st[l] == '{' && st[i]=='}') || (st[l]=='[' && st[i]==']'))
                kq = min(kq, trye(l+1,i-1) + trye(i+1,r));
    }
    f[l][r] = kq;
    return kq;
}

int main()
{
    freopen("dayngoac.inp","r",stdin);
    freopen("dayngoac.out","w",stdout);
    cin >> st;
    memset(f,-1,sizeof(f));
    cout << trye(0,st.size()-1);

    return 0;
}
