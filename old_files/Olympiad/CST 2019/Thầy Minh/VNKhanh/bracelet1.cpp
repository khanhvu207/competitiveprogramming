#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const long long inf = 2e9;
const int x = (1 << 11) + 5;
int n;
long long v[8], a[12][8];
long long dp[8][8][x];

long long rec (int f, int prv, int mask)
{
    if (dp[f][prv][mask] != -1) return dp[f][prv][mask];
    if (mask == (1 << n) - 1)
    {
        if (prv != f) return inf;
            else return v[f];
    }
    long long cnt = inf;
    for (int i = 0; i < n; ++i)
        if (!(mask & (1 << i)))
            for (int j = 0; j < 8; ++j)
                if (a[i][j] == prv)
                    cnt = min(cnt, rec(f, a[i][(j + 4) % 8], mask | (1 << i)) + v[a[i][j]]);
    dp[f][prv][mask] = cnt;
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("bracelet1.inp", "r", stdin);
    freopen("bracelet1.out", "w", stdout);

    while (cin >> n)
    {
        if (n < 1) return 0;
        for (int i = 0; i < 8; ++i) cin >> v[i];
        for (int i = 0; i < n; ++i)
        {
            string str;
            cin >> str;
            for (int j = 0; j < 8; ++j)
                a[i][j] = str[j] - 'A';
        }

        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                for (int mask = 0; mask < (1 << n); ++mask)
                    dp[i][j][mask] = -1;

        long long res = inf;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 8; ++j)
                res = min(res, rec(a[i][(j + 4) % 8], a[i][j], (1 << i)));
        if (res == inf) res = -1;
        cout << res << '\n';
    }
}
