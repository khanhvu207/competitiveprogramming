#include <bits/stdc++.h>

using namespace std;

int n,k,f,pre[100005],fa[100005],fb[100005];
long long base = 5000011;
int main()
{
    freopen("bieudien.inp","r",stdin);
    freopen("bieudien.out","w",stdout);
    cin >> n >> k;
    fa[0] = 1;
    fb[0] = 1;
    pre[0] = 1;
    for (int i=1; i<=n; i++)
    {
        if (i!=1) fb[i] = (fb[i-1] + fa[i-1]) % base;
        else fb[i] = fb[i-1];
        fa[i] = pre[max(0 , i-k-1)];
        pre[i] = (pre[i-1] + fa[i]) % base;
    }
    cout << (fb[n] + fa[n]) % base;
    return 0;
}
