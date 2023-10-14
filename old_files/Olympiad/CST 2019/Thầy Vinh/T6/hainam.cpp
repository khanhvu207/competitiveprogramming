#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n, m, d, k;
vector<vector<int> > a, dp;
vector<pair<int, int> > murshroom;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("hainam.inp", "r", stdin);
    freopen("hainam.out", "w", stdout);
    cin >> n >> m >> d >> k;
    a.resize(n+1, vector<int>(m+1, 0));
    dp.resize(n+1, vector<int>(m+1, 0));
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            char x; cin >> x;
            if (x=='M')
                murshroom.push_back(make_pair(i, j));
            else
            if (x=='S')
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            dp[i][j]=a[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    int res=0;
    for (int i=0; i<(int)murshroom.size(); ++i)
    {
        int x=murshroom[i].first;
        int y=murshroom[i].second;
        if (dp[min(x+d, n)][min(y+d, m)]-dp[max(x-d-1, 0)][min(y+d, m)]-dp[min(x+d, n)][max(y-d-1, 0)]+dp[max(x-d-1, 0)][max(y-d-1, 0)]>=k) ++res;
    }
    cout << res;
    return 0;
}
