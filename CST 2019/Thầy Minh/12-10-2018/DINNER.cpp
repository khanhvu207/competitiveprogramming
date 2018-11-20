#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int n, k, lang[115], cnt[115], dp[115][115][115];

int solve(int l, int r, int x) {
    if (dp[l][r][x] > -1) return dp[l][r][x];
    if (l == r) return dp[l][r][x] = (cnt[r] + x >= k ? 1 : n + 1);
    dp[l][r][x] = solve(l, r - 1, 0) + solve(r, r, x);
    for (int i = l; i < r; ++i)
        if (lang[i] == lang[r])
            dp[l][r][x] = min(dp[l][r][x], solve(i + 1, r - 1, 0) + solve(l, i, cnt[r] + x));
    return dp[l][r][x];
}

int main() {
    freopen("dinner.inp", "r", stdin);
    freopen("dinner.out", "w", stdout);
    scanf("%d %d\n", &n, &k);
    #define mask(c) (c == 'G' ? 0 : 1)
    for (int m = 0; n--;) {
        char c; scanf("%c", &c);
        if (!m || mask(c) != lang[m])
            lang[++m] = mask(c), cnt[m] = 1;
        else ++cnt[m];
        if (!n) {
            n = m; break;
        }
    }
    memset(dp, -1, sizeof dp);
    solve(1, n, 0);
    printf("%d", dp[1][n][0] <= n ? dp[1][n][0] : -1);
}
