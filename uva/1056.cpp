#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
const int inf = 5e8;
const int N = 100;

int n, m, cnt, f[N][N];
map<string, int> mp;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);

	int tc = 0;
	while (cin >> n >> m)
	{
		if (!n && !m) return 0;
		mp.clear();
		for (int i = 0; i <= 80; ++i)
			for (int j = 0; j <= 80; ++j)
				f[i][j] = inf;
		for (int i = 0; i < m; ++i)
		{
			string a, b;
			cin >> a >> b;
			if (!mp.count(a))
				mp[a] = mp.size();
			if (!mp.count(b))
				mp[b] = mp.size();
			f[mp[a]][mp[b]] = f[mp[b]][mp[a]] = 1;
		}
		int res = -1;

		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		for (int i = 1; i <= n - 1; ++i)
			for (int j = i + 1; j <= n; ++j)
				res = max(res, f[i][j]);
		cout << "Network " << ++tc << ": ";
		if (res == inf)
			cout << "DISCONNECTED\n";
		else
			cout << res << '\n';
		cout << '\n';
	}
}