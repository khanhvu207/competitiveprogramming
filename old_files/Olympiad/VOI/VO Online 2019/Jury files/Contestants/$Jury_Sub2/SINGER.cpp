#include <stdio.h>
#include <algorithm>

int f[444][444]; // forward dp, O(N^3)
int n, d, t;

int main() {
#ifdef THEMIS
    freopen("SINGER.INP", "r", stdin);
    freopen("SINGER.OUT", "w", stdout);
#endif // THEMIS

	scanf("%d%d%d", &n, &d, &t);
	f[0][0] = 2;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= i; ++j) if (f[i][j])
			for (int k = i + 1; k <= n; ++k)
				(f[k][j + std::max(k - i - d + 2, 0)] += f[i][j]) %= 998244353;
	printf("%d\n", f[n][t]);
}
