#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 5015;

int n, best = N, worst = 0;
int h[N], f[N];
vector<int> g[N], ansbest, answorst;

void DFS1(int u, int p)
{
	h[u] = 0;
	f[u] = 0;
	int id;
	for (int v : g[u])
		if (v != p)
		{
			DFS1(v, u);
			if (h[u] < h[v])
			{
				id = v;
				h[u] = h[v];
			}
		}
	for (int v : g[u])
		if (v != p && v != id)
			f[u] = max(f[u], h[v]);
	++h[u]; ++f[u];
}

void DFS2(int u, int p, int otherh)
{
	int tmph = max(otherh, h[u]);
	if (tmph <= best)
	{
		if (tmph < best)
		{
			best = tmph;
			ansbest.clear();
			ansbest.emplace_back(u);
		} else ansbest.emplace_back(u);
	}
	if (tmph >= worst)
	{
		if (tmph > worst)
		{
			worst = tmph;
			answorst.clear();
			answorst.emplace_back(u);
		} else answorst.emplace_back(u);
	}
	for (int v : g[u])
		if (v != p)
		{
			int t = (h[v] + 1 == h[u] ? f[u] : h[u]);
			DFS2(v, u, max(otherh, t) + 1);
		}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	while (cin >> n)
	{
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 1; i <= n; ++i) 
		{
			int m; 
			cin >> m;
			for (int j = 0; j < m; ++j) 
			{
				int u; 
				cin >> u;
				g[i].emplace_back(u);
			}
		}
		DFS1(1, -1);
		best = N;
		worst = 0;
		ansbest.clear();
		answorst.clear();
		DFS2(1, -1, 1);
		sort(ansbest.begin(), ansbest.end());
		sort(answorst.begin(), answorst.end());
		cout << "Best Roots  : ";
		for (int i = 0; i < (int)ansbest.size(); ++i)
		{
			if (i != 0) cout << ' ';
			cout << ansbest[i];
		}
		cout << '\n';
		cout << "Worst Roots : ";
		for (int i = 0; i < (int)answorst.size(); ++i)
		{
			if (i != 0) cout << ' ';
			cout << answorst[i];
		}
		cout << '\n';
	}
}