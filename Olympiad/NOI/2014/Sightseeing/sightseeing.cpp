#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int> > Edges;

int v, e, q;
int r[500015], p[500015], res[500015];
vector<Edges> E;
vector<vector<pair<int, int> > > g;

bool joint (int u, int v)
{
	while (u != p[u]) p[u] = p[p[u]], u = p[u];
	while (v != p[v]) p[v] = p[p[v]], v = p[v];
	if (u == v) return false;
	if (r[u] > r[v]) 
		r[u] += r[v], p[v] = u;
	else
		r[v] += r[u], p[u] = v;
	return true;
}

void dfs (int u, int p, int opt)
{
	if (u != 1) 
		res[u] = opt;
	for (pair<int, int> x : g[u])
		if (x.first != p) dfs(x.first, u, min(opt, x.second));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> v >> e >> q;
	g.resize(v + 5);
	for (int i = 0, a, b, c; i < e; ++i)
		cin >> a >> b >> c,
		E.push_back({c, {a, b}});
	sort(E.begin(), E.end());
	reverse(E.begin(), E.end());
	for (int u = 1; u <= v; ++u)
		r[u] = 1, p[u] = u;
	for (int i = 0; i < (int)E.size(); ++i)
		if (joint(E[i].second.first, E[i].second.second))
			g[E[i].second.first].push_back({E[i].second.second, E[i].first}),
			g[E[i].second.second].push_back({E[i].second.first, E[i].first});
	dfs(1, -1, 1e9);
	for (; q; --q)
	{
		int x; cin >> x;
		cout << res[x] << '\n';
	}
}