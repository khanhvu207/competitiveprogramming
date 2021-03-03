#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t, n, m;
bool vst[100015];
vector<int> g[100015];

void dfs (int u)
{
	vst[u]=1;
	for (int v : g[u])
		if (!vst[v]) dfs(v);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i=0; i<n; i++) g[i].clear();
		for (int i=0, u, v; i<m; i++)
			cin >> u >> v,
			g[u].push_back(v),
			g[v].push_back(u);
		memset(vst, 0, sizeof vst);
		int cnt=0;
		for (int i=0; i<n; i++)
			if (!vst[i]) dfs(i), ++cnt;
		cout << cnt << '\n';
	}
	return 0;
}