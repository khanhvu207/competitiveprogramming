#include <iostream>
#include <cstdio>
using namespace std;
const int inf = 1e9;

int n, m, f[115][115];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int tc, C = 0; cin >> tc;
	while (tc--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				f[i][j] = inf;
		for (int i = 0, u, v; i < m; ++i)
		{
			cin >> u >> v;
			f[u][v] = f[v][u] = 1;
		}
		for (int i = 0; i < n; ++i) f[i][i] = 0;
		for (int k = 0; k < n; ++k)
			for (int u = 0; u < n; ++u)
				for (int v = 0; v < n; ++v)
					if (u != k && v != k && u != v)
						f[u][v] = min(f[u][v], f[u][k] + f[k][v]);
		int s, t, res = 0;
		cin >> s >> t;
		for (int u = 0; u < n; ++u)
			res = max(res, f[s][u] + f[u][t]);
		cout << "Case " << ++C << ": " << res << '\n';
	}
}