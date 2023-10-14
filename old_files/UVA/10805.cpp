#include <iostream>
#include <cstdio>
using namespace std;
const int N = 500;
const int inf = 500;

int n, m, f[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int tc, C = 0;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n + m; ++i)
			for (int j = 0; j < n + m; ++j)
				f[i][j] = inf;

		int splitnode = n;
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			f[u][splitnode] = f[splitnode][u] = 1;
			f[v][splitnode] = f[splitnode][v] = 1;
			++splitnode;
			// - u --- splitnode --- v - (we use this kind of splitting node to ensure the diameter of the tree is always even
		}

		for (int i = 0; i < splitnode; ++i)
			f[i][i] = 0;
		for (int k = 0; k < splitnode; ++k)
			for (int i = 0; i < splitnode; ++i)
				for (int j = 0; j < splitnode; ++j)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

		int res = inf;
		for (int u = 0; u < splitnode; ++u) {
			int first = 0, second = 0;
			for (int v = 0; v < n; ++v)
				if (f[u][v] >= first) {
					second = first;
					first = f[u][v];
				} else 
					second = max(second, f[u][v]);
			//for each vertex we find two nodes such that its distance to the current one is equally greatest
			res = min(res, first + second);
		}

		cout << "Case #" << ++C << ":\n";
		cout << res / 2 << '\n';
		cout << '\n';
	}
}