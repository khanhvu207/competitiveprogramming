#include <iostream>
#include <iomanip>
using namespace std;

int n, a[115];
double b, r, v, e, f, dp[115], L[10015];

int main()
{
    while (cin >> n)
    {
        if (n < 1) return 0;

        for (int i = 0; i < n; ++i) cin >> a[i];
        cin >> b >> r >> v >> e >> f;

        for (int i = 1; i <= 10000; ++i)
            L[i] = L[i - 1] + (1.0 / (v - (i - 1 >= r ? (e * (i - 1 - r)) : (f * (r - i + 1)))));

        for (int i = 0; i < n; ++i)
        {
            dp[i] = L[a[i]] + (i != n - 1 ? b : 0.0);
            for (int j = i - 1; j >= 0; --j)
                dp[i] = min(dp[i], dp[j] + L[a[i] - a[j]] + (i != n - 1 ? b : 0.0));
        }
        cout << fixed << setprecision(4) << dp[n - 1] << '\n';
    }
}
