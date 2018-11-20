#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int n, m, par[250015][25], h[250015];
vector<int> g[250015];

void dfs(int u, int p)
{
	par[u][0]=p;
	if (p>0) h[u]=h[p]+1;
	for (int i=1; i<(int)log2(n); i++)
		par[u][i]=par[par[u][i-1]][i-1];
	for (int i=0; i<(int)g[u].size(); i++)
		if (p!=g[u][i]) dfs(g[u][i], u);
}

int lca(int u, int v)
{
	if (h[v]<h[u])
		swap(u, v);
	for (int i=(int)log2(n)-1; i>=0; i--)
		if (par[v][i]!=-1 && h[par[v][i]]>=h[u]) v=par[v][i];
	if (v==u) return v;
	for (int i=(int)log2(n)-1; i>=0; i--)
		if (par[v][i]!=par[u][i])
			v=par[v][i],
			u=par[u][i];
	return par[v][0];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("baitho.inp", "r", stdin);
	freopen("baitho.out", "w", stdout);
	cin >> n >> m;
	for (int i=0, u, v; i<n-1; i++)
		cin >> u >> v,
		g[u].push_back(v),
		g[v].push_back(u);
	memset(par, -1, sizeof par);
	dfs(1, -1);
	int res = 0;
	for (int i=0, u, v; i<m; i++)
	{
		cin >> u >> v;
		int x=lca(u, v);
		res+=2*(h[u]+h[v]-2*h[x]);
	}
	cout << res;
	return 0;
}