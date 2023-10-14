#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n, v[6], a[10015];
bool flag[6];
long long dp[10015];
int trace[10015];
pair<pair<int, int>, int> res[10015];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("paint.inp", "r", stdin);
    freopen("paint.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= 5; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) trace[i] = -1;

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        trace[i] = i - 1;
        for (int i = 0; i <= 4; ++i)
            flag[i] = true;
        flag[5] = abs(a[i]) % 4 == 0;
        for (int j = i - 1; j >= 1; --j)
        {
            flag[1] &= a[j] <= a[j + 1];
            flag[2] &= a[j] >= a[j + 1];
            flag[3] &= abs(a[j] + a[j + 1]) % 2 == 0;
            flag[4] &= abs(a[j] + a[j + 1]) % 2 == 1;
            flag[5] &= abs(a[j]) % 4 == 0;
            if (i - j + 1 < 3) continue;
            for (int k = 0; k <= 5; ++k)
                if (flag[k] && dp[i] < dp[j - 1] + (i - j + 1) * v[k])
                {
                    dp[i] = dp[j - 1] + (i - j + 1) * v[k];
                    trace[i] = j - 1;
                    res[i] = {{i, j}, k};
                }
        }
    }
    cout << dp[n] << '\n';
    int x = n;
    while (x != 0)
    {
        if (res[x].second != 0)
            cout << res[x].first.first << ' ' << res[x].first.second << ' ' << res[x].second << '\n';
        x = trace[x];
    }
}
