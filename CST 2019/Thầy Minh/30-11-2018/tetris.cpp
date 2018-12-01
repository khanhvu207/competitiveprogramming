#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, p, a[255], b[255], c[255];
long long kpowm[255][10], dp[255][255][255];

void precalc()
{
    for (int k = 1; k <= 250; ++k)
        for (int m = 0; m <= 5; ++m)
            kpowm[k][m] = (m < 1 ? 1ll : kpowm[k][m - 1] * k * 1ll);
}

void winrar()
{
    p = 0;
    c[p] = a[0];
    b[p] = 1;
    for (int i = 1; i < n; ++i)
        if (a[i] == a[i - 1])
            b[p]++;
        else
        {
            ++p;
            c[p] = a[i];
            b[p] = 1;
        }
}

long long solve(int l, int r, int k)
{
    if (dp[l][r][k] != -1ll) return dp[l][r][k];
    if (l == r) return kpowm[b[l] + k][c[l]];
    dp[l][r][k] = solve(l, r - 1, 0) + solve(r, r, k);
    for (int i = l; i < r; ++i)
        if (c[i] == c[r])
            dp[l][r][k] = max(dp[l][r][k], solve(i + 1, r - 1, 0) + solve(l, i, b[r] + k));
    return dp[l][r][k];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("tetris.inp", "r", stdin);
    freopen("tetris.out", "w", stdout);
    precalc();
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        winrar();
        memset(dp, -1ll, sizeof dp);
        cout << solve(0, p, 0) << '\n';
    }
}
