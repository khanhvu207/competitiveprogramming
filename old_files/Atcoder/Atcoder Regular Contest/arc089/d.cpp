#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 2020;
int a[N][N];
int m, n;
int ans = 0;

int getSum(int x1, int y1, int x2, int y2) {
	return a[x2][y2] + a[x1][y1] - a[x2][y1] - a[x1][y2];
}

int solve(int x, int y) {
	if (x <= n)
		return getSum(x, y, x + n, n) + getSum(0, 0, x, y) + getSum(x + n, 0, 2 * n, y);
	else
		return getSum(0, y, x - n, n) + getSum(x - n, 0, x, y) + getSum(x, y, 2 * n, n);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &m, &n);
	while(m--) {
		int x, y;
		char c;
		scanf("%d%d %c", &x, &y, &c);
		if (c == 'W')
			x += n;
		x %= 2 * n;
		y %= 2 * n;
		if (y >= n) {
			x += n;
			y -= n;
		}
		x %= 2 * n;
		a[x + 1][y + 1]++;
	}

	for (int x = 1; x < N; x++)
		for (int y = 1; y < N; y++)
			a[x][y] += a[x - 1][y] + a[x][y - 1] - a[x - 1][y - 1];

	for (int x = 0; x < 2 * n; x++)
		for (int y = 0; y < n; y++) {
			ans = max(ans, solve(x, y));
		}
	printf("%d\n", ans);

	return 0;
}
