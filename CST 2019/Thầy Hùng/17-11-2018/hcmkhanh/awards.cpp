#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int n;
map<pair<int, long long>, int> dp;
long long p[5015];

int solve (int cur, int prev)
{
    if (dp.count(make_pair(cur, prev))) return dp[{cur, prev}];
    if (cur>n) return 0;
    int cnt=0;
    for (int i=cur+1; i<=n; ++i)
        if (p[i]-p[cur]<=prev) cnt=max(cnt, solve(i, p[i]-p[cur])+1);
    cnt=max(cnt, solve(cur+1, prev+p[cur+1]-p[cur]));
    dp[{cur, prev}]=cnt;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("awards.inp", "r", stdin);
    freopen("awards.out", "w", stdout);
    cin >> n;
    for (int i=1, x; i<=n; ++i)
        cin >> x,
        p[i]=p[i-1]+x;
    cout << solve(0, 1e9);
}
