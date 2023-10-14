#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const long long inf = 2e9;

int n;
long long v[15], a[15][15];
long long dp[10][10][2222];

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
    freopen("bracelet2.inp", "r", stdin);
    freopen("bracelet2.out", "w", stdout);

    while (cin >> n)
    {
        if (n < 1) return 0;
        for (int i = 0; i < 8; ++i) cin >> v[i], v[i] = -v[i];
        for (int i = 0; i < n; ++i)
        {
            string str;
            cin >> str;
            for (int j = 0; j < 8; ++j)
                a[i][j] = str[j] - 'A';
        }

        memset(dp, -1, sizeof dp);
        long long res = inf;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 8; ++j)
                res = min(res, rec(a[i][(j + 4) % 8], a[i][j], (1 << i)));
        if (res > 0) res = -1;
            else res = -res;
        cout << res << '\n';
    }
}

