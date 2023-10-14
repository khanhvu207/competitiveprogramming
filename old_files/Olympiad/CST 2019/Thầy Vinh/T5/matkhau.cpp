#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, pn[1000015], pc[1000015], pl[1000015];
string s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("matkhau.inp", "r", stdin);
    freopen("matkhau.out", "w", stdout);
    cin >> s;
    n = s.size();
    for (int i=0; i<n; i++)
        pn[i]=(i<1?0:pn[i-1])+('0'<=s[i]&&s[i]<='9'),
        pc[i]=(i<1?0:pc[i-1])+('A'<=s[i]&&s[i]<='Z'),
        pl[i]=(i<1?0:pl[i-1])+('a'<=s[i]&&s[i]<='z');
    long long res=0ll;
    for (int r=5; r<n; r++)
    {
        if (pn[r]<1||pc[r]<1||pl[r]<1) continue;
        int xn=lower_bound(pn, pn+r, pn[r])-pn;
        int xc=lower_bound(pc, pc+r, pc[r])-pc;
        int xl=lower_bound(pl, pl+r, pl[r])-pl;
        if (pn[xn]<pn[r]) ++xn;
        if (pc[xc]<pc[r]) ++xc;
        if (pl[xl]<pl[r]) ++xl;
        long long l=min(xn, min(xc, xl))*1ll;
        l=min(l, r-6ll+1ll);
        res+=l+1ll;
    }
    cout << res;
    return 0;
}
