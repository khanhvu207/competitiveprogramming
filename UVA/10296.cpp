#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 16;
const int inf = 1e8;

int n, m, t, deg[N], f[N][N], dp[1 << N];
vector<int> node;

int rec(int mask) {
	if (dp[mask] != -1) 
		return dp[mask];
	if (mask == 0)
		return 0;
	dp[mask] = inf;
	for (int i = 0; i < t; ++i)
		if ((mask >> i) & 1)
			for (int j = 0; j < t; ++j)
				if (j != i && (mask >> j) & 1) {
					int tmask = (mask ^ (1 << i)) ^ (1 << j);
					dp[mask] = min(dp[mask], f[node[i]][node[j]] + rec(tmask));
				}
	return dp[mask];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	while (cin >> n) {
		if (!n) return 0;
		cin >> m;
		int res = 0;
		memset(deg, 0, sizeof deg);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				f[i][j] = inf;
		for (int i = 0, u, v, c; i < m; ++i) {
			cin >> u >> v >> c;
			f[u][v] = min(f[u][v], c);
			f[v][u] = min(f[v][u], c);
			++deg[u];
			++deg[v];
			res += c;
		}
		for (int i = 1; i <= n; ++i)
			f[i][i] = 0;
		for (int k = 1; k <= n; ++k)
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
		node.clear();
		for (int i = 1; i <= n; ++i)
			if (deg[i] & 1)
				node.push_back(i);
		t = node.size();
		memset(dp, -1, sizeof dp);
		res += rec((1 << t) - 1);
		cout << res << '\n';
	}
}