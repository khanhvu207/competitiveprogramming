#include <iostream>
using namespace std;

int t, n, dp[10000][10];

int main()
{
	for (int i = 1; i < 10000; ++i)
	{
		int x = i;
		for (int j = 0; j < 10; ++j)
			dp[i][j] += dp[i - 1][j];
		while (x) ++dp[i][x % 10], x /= 10;
	}

	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < 10; ++i)
		{
			cout << dp[n][i];
			if (i != 9) cout << ' ';
		}
		cout << '\n';
	}
}