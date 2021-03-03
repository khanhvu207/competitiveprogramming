#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

string s;
int k, q;
vector<vector<int> > dp;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("lrkpalin.inp", "r", stdin);
    freopen("lrkpalin.out", "w", stdout);
    cin>>s;
    int n=s.size();
    s='$'+s;
    dp.resize(n+5, vector<int>(n+5));
    for (int i=1; i<=n; i++) dp[i][i]=0;
    for (int i=1; i<=n-1; i++)
        dp[i][i+1]=(s[i]==s[i+1]?0:1);
    for (int len=3; len<=n; len++)
        for (int l=1, r=len; r<=n; l++, r++)
            if (s[l]==s[r]) dp[l][r]=dp[l+1][r-1];
            else dp[l][r]=dp[l+1][r-1]+1;
    cin>>k>>q;
    while (q--)
    {
        int l, r;
        cin>>l>>r;
        cout<<(dp[l][r]<=k?1:0)<<'\n';
    }
    return 0;
}
