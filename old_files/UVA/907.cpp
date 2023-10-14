#include <iostream>
#include <cstring>
using namespace std;
const int inf = 1e9;

int n, m, a[615], dp[615][315];

int f(int camp, int night)
{
	if (dp[camp][night] != -1) return dp[camp][night];
	if (camp == n)
	{
		if (night != 0) return inf;
		return a[n] - a[n - 1];
	}
	dp[camp][night] = inf;
	if (night == 0)
	{
		dp[camp][night] = a[n] - (camp != 0 ? a[camp - 1] : 0);
		return dp[camp][night];
	}
	for (int i = camp + 1; i <= n; ++i)
		dp[camp][night] = min(dp[camp][night], max(a[i - 1] - (camp != 0 ? a[camp - 1] : 0), f(i, night - 1)));
	return dp[camp][night];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	while (cin >> n >> m)
	{
		for (int i = 0; i <= n; ++i)
		{
			cin >> a[i];
			if (i > 0) a[i] += a[i - 1];
		}
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= m; ++j)
				dp[i][j] = -1;
		cout << f(0, m) << '\n';
	}
}