#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 100015;
const int N = 5015;
const long long inf = 1e18;

int n, m;
int cow[N];
long long cw[M], suffix[M], dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("chemua.inp", "r", stdin);
    freopen("chemua.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> cow[i];
    for (int i = 1; i <= m; ++i) cin >> cw[i];
    sort(cow + 1, cow + n + 1);

    suffix[m] = cw[m];
    for (int i = m - 1; i >= 1; --i)
        suffix[i] = min(cw[i], suffix[i + 1]);

    cow[0] = 0;
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + suffix[1];
        for (int j = i - 1; j >= 1; --j)
            dp[i] = min(dp[i], dp[j - 1] + suffix[cow[i] - cow[j] + 1]);
    }
    cout << dp[n];
}
