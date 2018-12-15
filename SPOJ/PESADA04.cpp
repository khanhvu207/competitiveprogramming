#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//using namespace std;
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
const long long inf = 1e9;
const int N = 15;

int n;
int c[15][15], dp[15][15][1 << 12];

int rec(int f, int pv, int mask)
{
	if (dp[f][pv][mask] != -1ll) return dp[f][pv][mask];
	if (mask == (1 << n) - 1)
		return c[pv][f];
	dp[f][pv][mask] = inf;
	for (int i = 0; i < n; ++i)
		if (i != pv && !((mask >> i) & 1))
			dp[f][pv][mask] = min(dp[f][pv][mask], c[pv][i] + rec(f, i, mask | (1 << i)));
	return dp[f][pv][mask];
}

int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		++n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (j != i) scanf("%d", &c[i][j]);
		int res = inf;
		memset(dp, -1ll, sizeof dp);
		for (int i = 0; i < n; ++i)
			res = min(res, rec(i, i, 1 << i));
		printf("%d\n", res);
	}
}