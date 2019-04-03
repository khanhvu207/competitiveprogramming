#include <bits/stdc++.h>
using namespace std;

int n, k, g[444], p[444], m[444], f[444][444], res = 1e9;

int main()
{
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> g[i];
	p[0] = g[0];
	for (int i = 1; i < n; ++i)
		p[i] = p[i - 1] + g[i];
	m[0] = g[0];
	for (int i = 1; i < n; ++i)
		m[i] = max(m[i - 1], g[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 1; j <= k + 1; ++j)
		{
			f[i][j] = (j != 1 ? 1e9 : m[i] * (i + 1) - p[i]);
			if (j == 1) continue;
			int mx = g[i];
			for (int h = i - 1; h >= 0; --h)
			{
				mx = max(mx, g[h + 1]);
				f[i][j] = min(f[i][j], f[h][j - 1] + mx * (i - h) - p[i] + p[h]);
			}
			if (i == n - 1)
				res = min(res, f[i][j]);
		}
	cout << res;
}