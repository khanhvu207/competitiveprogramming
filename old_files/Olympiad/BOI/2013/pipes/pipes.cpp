#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;
 
int n, m, child[100015], tmp[100015];
long long d[100015], res[500015];
vector<pair<int, int> > g[100015];
pair<int, int> p[100015];
queue<int> q;
 
int color[100015], cycleStart, cycleEnd;
bool flag = 0, inCycle[100015];
pair<int, int> par[100015];
vector<int> Ncycle;
 
void findcycle (int u, int pv)
{
	color[u] = 1;
	for (int i = 0; i < (int)g[u].size(); ++i)
	{
		if (flag) return;
		int v = g[u][i].first;
		if (color[v] == 0)
		{
			findcycle(v, u);
			par[v] = {u, g[u][i].second};
		}
		else if (color[v] == 1 && v != pv)
		{
			cycleStart = v;
			cycleEnd = u;
			flag = 1;
			return;
		}
	}
	color[u] = 2;
}
 
void dfsx (int u, int pv)
{
	child[u] = 0;
	for (int i = 0; i < (int)g[u].size(); ++i)
	{
		int v = g[u][i].first;
		if (v == pv || inCycle[v]) continue;
		dfsx(v, u);
		child[u] += child[v] + 1;
		p[v] = {u, g[u][i].second};
	}
}
 
void caseCycle()
{
	findcycle(1, -1);
	int tEnd = cycleEnd;
	while (cycleEnd != cycleStart)
	{
		inCycle[cycleEnd] = 1;
		Ncycle.push_back(cycleEnd);
		cycleEnd = par[cycleEnd].first;
	}
	inCycle[cycleStart] = 1;
	Ncycle.push_back(cycleStart);
 
	if ((int)Ncycle.size() % 2 == 0)
	{
		cout << 0;
		return;
	}
 
	for (int i = 0; i < (int)Ncycle.size(); ++i)
		dfsx(Ncycle[i], -1);
 
	for (int i = 1; i <= n; ++i)
		tmp[i] = child[i];
 
	for (int i = 1; i <= n; ++i)
		if (child[i] == 0 && !inCycle[i]) q.push(i);
 
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		d[p[u].first] -= d[u];
		child[p[u].first] -= (tmp[u] + 1);
 
		res[p[u].second] = d[u];
		if (child[p[u].first] < 1 && !inCycle[p[u].first]) q.push(p[u].first);		
	}
	
 
	long long sum = 0;
	for (int i = 0; i < (int)Ncycle.size(); ++i)
		sum += d[Ncycle[i]] * (i & 1 ? -1 : 1);
	sum /= 2;
	for (int i = 0; i < (int)g[cycleStart].size(); ++i)
		if (g[cycleStart][i].first == tEnd)
		{
			res[g[cycleStart][i].second] = sum;
			d[cycleStart] -= sum;
			d[tEnd] -= sum;
			break;
		}
	while (tEnd != cycleStart)
	{
		res[par[tEnd].second] = d[tEnd];
		d[par[tEnd].first] -= d[tEnd];
		tEnd = par[tEnd].first;
	}
	for (int id = 1; id <= m; ++id)
		cout << res[id] << '\n';
}
 
void dfs (int u, int pv)
{
	child[u] = 0;
	for (int i = 0; i < (int)g[u].size(); ++i)
	{
		int v = g[u][i].first;
		if (v == pv) continue;
 
		dfs(v, u);
		child[u] += child[v] + 1;
		p[v] = {u, g[u][i].second};
	}
}
 
void caseTree()
{
	p[1] = {-1, -1};
	dfs(1, -1);
 
	for (int i = 2; i <= n; ++i)
		if (child[i] == 0) q.push(i);	
	for (int i = 1; i <= n; ++i)
		tmp[i] = child[i];
 
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		d[p[u].first] -= d[u];
		child[p[u].first] -= (tmp[u] + 1);
 
		if (p[u].first != -1) res[p[u].second] = d[u];
		if (child[p[u].first] < 1 && p[u].first != -1) q.push(p[u].first);
	}
	for (int id = 1; id <= m; ++id)
		cout << res[id] << '\n';
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> d[i],
		d[i] *= 2;
	for (int i = 0, u, v; i < m; ++i)
	{
		cin >> u >> v;
		g[u].push_back({v, i + 1});
		g[v].push_back({u, i + 1});
 	}
	if (m == n - 1) 
		caseTree();
	else if (m == n)
		caseCycle();
	else
		cout << 0;
}