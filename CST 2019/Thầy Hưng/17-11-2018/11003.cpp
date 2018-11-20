#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
int wt[1015], load[1015];
vector<vector<int> > dp;

int solve (int cur, int prevWt)
{
    if (cur<0) return 0;
    if (prevWt>6000) return -1e9;
    if (dp[cur][prevWt]!=-1) return dp[cur][prevWt];
    int cnt=0;
    for (int i=cur; i>=0; --i)
        if (load[i]>=prevWt)
            cnt=max(cnt, solve(i-1, prevWt+wt[i])+1);
    dp[cur][prevWt]=cnt;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("11003.inp", "r", stdin);
    freopen("11003.out", "w", stdout);
    while (cin >> n)
    {
        if (n<1) return 0;
        for (int i=0; i<n; ++i)
            cin >> wt[i] >> load[i];
        dp.resize(n+5, vector<int>(6015, -1));
        cout << solve(n-1, 0) << '\n';
    }
}
