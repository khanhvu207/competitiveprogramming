#include <bits/stdc++.h>

using namespace std;

long long n, K, M, cnt[1000005] = {0}, p[1000005], res = 0, dp[5005][5005], maxx = 0;

void sieve()
{
    for (int i = 1; i <= 1000001; i++) p[i] = i;
    for (int i = 2; i <= sqrt(1000001); i++)
    {
        if (p[i] != i) continue;
        for (int j = 2; j <= (1000000 / i); j++) p[i * j] = i;
    }
}


long long optimize(int c, int s)
{
    if (s == 0) return (c == 1 ? 1 : 0);
    if (dp[c][s] != -1) return dp[c][s];
    long long res = 0;
    if (c - 1 == 0) res = (res + optimize(n, s - 1)) % M; else res = (res + optimize(c - 1, s - 1)) % M;
    if (c == n) res = (res + optimize(1, s - 1)) % M; else res = (res + optimize(c + 1, s - 1)) % M;
    dp[c][s] = res;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("JUMP.INP", "r", stdin);
    freopen("JUMP.OUT", "w", stdout);

    cin >> n >> K >> M;
    if (K <= 5000)
    {
        memset(dp, -1, sizeof dp);
        long long res = optimize(1, K);
        cout << res;
        return 0;
    }
    sieve();
    for (int F = 0; F <= K; F++)
    {
        int B = K - F;
        if (abs(F - B) % n == 0)
        {
            long long C = 1ll;
            for (int i = 2; i <= K; i++) {
                    for (int j = 1; j <= cnt[i]; j++) C = (C * i) % M;
            }
            res = (res + C) % M;
            long long x = K - F, y = F + 1;
            while (x > 1) cnt[p[x]]++, x /= p[x];
            while (y > 1) cnt[p[y]]--, y /= p[y];
        }else {
            long long x = K - F, y = F + 1;
            while (x > 1) cnt[p[x]]++, x /= p[x];
            while (y > 1) cnt[p[y]]--, y /= p[y];
        }
    }
    cout << res;

    return 0;
}
