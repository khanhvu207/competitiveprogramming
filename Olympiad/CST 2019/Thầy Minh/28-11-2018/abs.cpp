#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long k;
long long dp[188][188];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("abs.inp", "r", stdin);
    freopen("abs.out", "w", stdout);

    while (cin >> n >> k)
    {
        for (int a = 0; a <= n; ++a)
            dp[a][n - a] = (a < n - a);
        for (int i = n - 1; i >= 0; --i)
            for (int a = 0; a <= i; ++a)
            {
                dp[a][i - a] = dp[a + 1][i - a] + dp[a][i - a + 1];
                if (dp[a][i - a] > 1e18) dp[a][i - a] = 1e18;

            }
        int a = 0;
        int b = 0;
        if (dp[0][0] < k)
        {
            cout << -1 << '\n';
            continue;
        }
        while (a + b < n)
        {
            if (dp[a + 1][b] >= k)
                cout << 'A', ++a;
            else
                k -= dp[a + 1][b],
                cout << 'B', ++b;
        }
        cout << '\n';
    }
}
