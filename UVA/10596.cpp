#include <bits/stdc++.h>
using namespace std;
const int N = 222;

int deg[N];
bool vis[N];
vector<int> g[N];

void DFS(int u) {
	vis[u] = true;
	for (int v : g[u])
		if (!vis[v])
			DFS(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	while (cin >> n >> m) {
		if (m < 1) {
			cout << "Not Possible\n";
			continue;
		}
		int start = -1;
		vector<int> node;
		for (int i = 0; i < N; ++i)
			g[i].clear(), vis[i] = false, deg[i] = 0;
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			if (start == -1) 
				start = u;
			node.push_back(u);
			node.push_back(v);
			g[u].push_back(v);
			g[v].push_back(u);
			++deg[u];
			++deg[v];
		}
		DFS(start);
		bool good = true;
		for (int u : node)
			if (deg[u] & 1 || !vis[u]) {
				good = false;
				break;
			}
		if (!good)
			cout << "Not Possible\n";
		else
			cout << "Possible\n";
	}
}