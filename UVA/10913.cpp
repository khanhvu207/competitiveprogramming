#include <iostream>
#include <cstring>
using namespace std;
const long long inf = 1e18;

int N, K;
long long a[80][80], dp[80][80][10][2];

long long rec(int x, int y, int k, bool l)
{
	k += (a[x][y] < 0);
	if (k > K) return -inf;
	if (dp[x][y][k][l] != -1) return dp[x][y][k][l];
	if (x == N - 1 && y == N - 1)
	{
		if (k > K) return -inf;
			else return a[x][y];
	}
	dp[x][y][k][l] = -inf;
	if (!l && y + 1 < N)
		dp[x][y][k][l] = max(dp[x][y][k][l], rec(x, y + 1, k, 0) + a[x][y]);
	if (l && y - 1 >= 0)
		dp[x][y][k][l] = max(dp[x][y][k][l], rec(x, y - 1, k, 1) + a[x][y]);
	if (x + 1 < N)
		dp[x][y][k][l] = max(dp[x][y][k][l], max(rec(x + 1, y, k, 0), rec(x + 1, y, k, 1)) + a[x][y]);
	return dp[x][y][k][l];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);

	int tc = 0;
	while (cin >> N >> K)
	{
		if (!N && !K) return 0;
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				cin >> a[i][j];
		memset(dp, -1, sizeof dp);
		cout << "Case " << ++tc << ": ";
		long long res = rec(0, 0, 0, 0);
		if (res < -1000000000)
			cout << "impossible\n";
		else
			cout << res << '\n';
	}
}