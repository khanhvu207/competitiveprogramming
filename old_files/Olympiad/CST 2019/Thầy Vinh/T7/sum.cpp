#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long mod = 1e9 + 7;
int n, k;
string a;
long long dp[1015][1015][2];

long long solve (int i, int cnt, int memo)
{
    if (i == n)
        return ((cnt + memo) == k) * 1ll % mod;
    if (dp[i][cnt][memo]!= -1) return dp[i][cnt][memo];
    long long sum = 0;
    if (memo)
    {
        sum = (sum + solve(i + 1, cnt + (a[i] - '0' != 1), (a[i] - '0' == 1)) % mod) % mod;
        sum = (sum + solve(i + 1, cnt + (a[i] - '0' == 1), 1) % mod) % mod;
    } else
    {
        sum = (sum + solve(i + 1, cnt + (a[i] - '0' == 1), 0) % mod) % mod;
        sum = (sum + solve(i + 1, cnt + (a[i] - '0' == 0), (a[i] - '0' == 1)) % mod) % mod;
    }
    dp[i][cnt][memo] = sum % mod;
    return sum % mod;
}

int main()
{
    freopen("sum.inp", "r", stdin);
    freopen("sum.out", "w", stdout);
    cin >> n >> k;
    cin >> a;
    reverse(a.begin(), a.end());

    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0) % mod;
}
