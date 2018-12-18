#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100015;

int n, m, c, a[N];

bool chk(int wait)
{
	int i = 1;
	int bus = m;
	while (i <= n && bus)
	{
		int p = upper_bound(a + 1, a + n + 1, a[i] + wait) - a;
		while (a[p] > a[i] + wait || p > n) --p;
		while (p - i + 1 > c) --p;
		i = p + 1;
		--bus;
	}
	if (bus == 0 && i <= n) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);

	cin >> n >> m >> c;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 0, r = 0;
	for (int i = c, j = 1; j <= i;)
	{ 
		r = max(r, a[i] - a[j]);
		j = i + 1;
		i = min(i + c, n);
	}
	int res = 0;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (chk(m)) r = m - 1, res = m;
			else l = m + 1;
	}
	cout << res;
}