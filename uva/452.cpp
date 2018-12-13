#include <iostream>
#include <sstream>
#include <vector>
#include <cstdio>
using namespace std;
const int inf = 1e9;
const int N = 30;
int start, last, w[N], f[N];
vector<int> g[N], p[N], topo;
bool vis[N], mark[N];

void DFS(int u)
{
	vis[u] = true;
	for (int v : g[u])
		if (!vis[v]) DFS(v);
	topo.push_back(u);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int tc;
	cin >> tc;
	string line;
	getline(cin, line);
	getline(cin, line);
	while (tc--)
	{
		for (int i = 0; i < 30; ++i) 
			g[i].clear(), vis[i] = false, p[i].clear(), mark[i] = false;
		while (true)
		{
			if (!getline(cin, line)) break;
			if (line == "") break;
			stringstream buffer(line);
			char c;
			buffer >> c;
			int u = c - 'A';
			mark[u] = true;
			buffer >> w[u]; 
			string s;
			buffer >> s;
			for (char v : s)
				g[v - 'A'].push_back(u),
				p[u].push_back(v - 'A');
		}
		topo.clear();
		for (int u = 0; u < 27; ++u)
			if (mark[u] && !vis[u]) DFS(u);

		int res = 0;
		for (int i = (int)topo.size() - 1; i >= 0; --i)
		{
			int u = topo[i];
			f[u] = 0;
			for (int v : p[u])
				f[u] = max(f[u], f[v]);
			f[u] += w[u];
			res = max(res, f[u]);
		}
		cout << res << '\n';
		if (tc > 0) cout << '\n';
	}
}