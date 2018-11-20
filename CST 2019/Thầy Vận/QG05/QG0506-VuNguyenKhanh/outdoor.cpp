#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int n, m, f, dp[200][200], c[200][200];
vector<pair<int, int> > g;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("outdoor.inp", "r", stdin);
    freopen("outdoor.out", "w", stdout);
    cin >> n >> m >> f;
    for (int i=0, x, y; i<f; i++)
    {
        cin >> x >> y;
        if (x>y) swap(x, y);
        g.push_back(make_pair(x, y));
    }
    for (int i=1; i<=n-1; i++)
        for (int j=i+1; j<=n; j++)
            for (int k=0; k<(int)g.size(); k++)
                c[i][j]+=(g[k].first>=i&&g[k].second<=j);

    for (int i=1; i<=n; i++)
        dp[i][1]=c[1][i];

    for (int i=2; i<=n; i++)
        for (int k=2; k<=m; k++)
            for (int j=i-1; j>2*(k-1); j--)
                dp[i][k]=max(dp[i][k], dp[j-1][k-1]+c[j][i]);

    cout << dp[n][m];
    return 0;
}
