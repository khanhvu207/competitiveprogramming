#include <iostream>
#include <cstring>
using namespace std;

int t, n, h, f, acorn[2015][2015], dp[2015];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n >> h >> f;
        memset(acorn, 0, sizeof acorn);
        memset(dp, 0, sizeof dp);
        for (int i=0, m; i<n; ++i)
        {
            cin >> m;
            for (int j=0, x; j<m; ++j)
                cin >> x, acorn[i][x]++;
        }
        for (int tree=0; tree<n; ++tree)
            dp[h]=max(dp[h], acorn[tree][h]);

        for (int H=h-1; H>=0; --H)
            for (int tree=0; tree<n; ++tree)
            {
                acorn[tree][H]+=max(acorn[tree][H+1], (H<=h-f?dp[H+f]:0));
                dp[H]=max(dp[H], acorn[tree][H]);
            }
        cout << dp[0] << '\n';
    }
}
