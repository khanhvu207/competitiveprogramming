#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 115;

int n, m, id[N][N], a[N][N], p[N * N], f[N * N], res;
bool vis[N * N];
string name;
vector<vector<int> > adj;

void DFS(int u)
{
	vis[u] = true;
	if (adj[u].empty())
	{
		f[u] = 1;
		return;
	}
	f[u] = 0;
	for (int v : adj[u])
	{
		if (!vis[v]) DFS(v);
		f[u] = max(f[u], f[v]);
	}
	res = max(res, ++f[u]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> name >> n >> m;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				id[i][j] = cnt++;
				cin >> a[i][j];
			}
		
		adj.resize(cnt + 15);
		for (int i = 0; i < cnt + 15; ++i) 
			adj[i].clear(), vis[i] = false, p[i] = 0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				if (i - 1 >= 0 && a[i][j] > a[i - 1][j])
					adj[id[i][j]].push_back(id[i - 1][j]),
					++p[id[i - 1][j]];
				if (i + 1 < n && a[i][j] > a[i + 1][j])
					adj[id[i][j]].push_back(id[i + 1][j]),
					++p[id[i + 1][j]];
				if (j - 1 >= 0 && a[i][j] > a[i][j - 1])
					adj[id[i][j]].push_back(id[i][j - 1]),
					++p[id[i][j - 1]];
				if (j + 1 < m && a[i][j] > a[i][j + 1])
					adj[id[i][j]].push_back(id[i][j + 1]),
					++p[id[i][j + 1]];
			}

		res = 1;
		for (int i = 0; i < cnt; ++i)
			if (p[i] < 1 && !vis[i]) DFS(i);
		cout << name << ": " << res << '\n';
	}
}