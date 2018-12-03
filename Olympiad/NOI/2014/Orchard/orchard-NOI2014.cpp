#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, m;
vector<int> suff;
vector<vector<int> > a, dp, pref, sum;

void solve_3()
{
	int ans = 1e9;
	suff.resize(m + 5, 0);
	dp.resize(m + 5, vector<int>(2, 0));
	for (int i = m; i >= 1; --i) suff[i] = suff[i + 1] + (a[1][i] == 1);
	for (int i = 1; i <= m; ++i)
	{
		dp[i][0] = dp[i - 1][0] + (a[1][i] == 1);
		dp[i][1] = min(dp[i - 1][1] + (a[1][i] == 0), dp[i - 1][0] + (a[1][i] == 1));
		ans = min(ans, dp[i][1] + suff[i + 1]);
	}
	cout << ans;
}

void solve_f()
{
	int ans = 1e9;
	suff.resize(m + 5, 0);
	dp.resize(m + 5, vector<int>(2, 0));
	pref.resize(n + 5, vector<int>(m + 5, 0));
	sum.resize(n + 5, vector<int>(m + 5, 0));
	
	for (int c = 1; c <= m; ++c)
		for (int r = 1; r <= n; ++r)
			pref[r][c] = pref[r - 1][c] + (a[r][c] == 1);
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			sum[i][j] = (a[i][j] == 1) + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

	for (int d = 1; d <= n; ++d)
		for (int u = d; u >= 1; --u)
		{
			for (int i = m; i >= 1; --i)
				suff[i] = suff[i + 1] + pref[d][i] - pref[u - 1][i];
			for (int i = 1; i <= m; ++i)
			{
				dp[i][0] = dp[i - 1][0] + pref[d][i] - pref[u - 1][i];
				dp[i][1] = min(dp[i - 1][1] + (d - u + 1) - pref[d][i] + pref[u - 1][i], dp[i - 1][0] + pref[d][i] - pref[u - 1][i]);
				ans = min(ans, dp[i][1] + suff[i + 1] + sum[u - 1][m] + sum[n][m] - sum[d][m]);
			}	
		}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	a.resize(n + 5, vector<int>(m + 5, 0));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	if (n == 1)
		solve_3();
	else
		solve_f();
}