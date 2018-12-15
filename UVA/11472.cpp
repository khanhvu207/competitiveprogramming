#include <iostream>
#include <cstring>
using namespace std;
const long long MOD = 1e9 + 7;

int n, m;
long long dp[115][15][1250];

long long f(int cur, int pv, int mask)
{
	if (dp[cur][pv][mask] != -1ll) return dp[cur][pv][mask];
	if (cur == m)
		return (mask == (1 << n) - 1) * 1ll;
	dp[cur][pv][mask] = (mask == (1 << n) - 1);
	if (pv + 1 < n) dp[cur][pv][mask] = (dp[cur][pv][mask] + f(cur + 1, pv + 1, mask | (1 << (pv + 1)))) % MOD;
	if (pv - 1 >= 0) dp[cur][pv][mask] = (dp[cur][pv][mask] + f(cur + 1, pv - 1, mask | (1 << (pv - 1)))) % MOD;
	return dp[cur][pv][mask];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	//freopen("input.in", "r", stdin);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m;
		if (m < n)
		{
			cout << 0 << '\n';
			continue;
		}
		memset(dp, -1ll, sizeof dp);
		long long res = 0ll;
		for (int i = 1; i < n; ++i)
			res = (res + f(1, i, (1 << i))) % MOD;
		cout << res << '\n';
	}
}