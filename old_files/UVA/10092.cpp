#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

int n, m, s, t, f, tot;
int r[1111][1111], p[1111];
vector<int> g[1111];

void fileio()
{
	s = 0, t = n + m + 1, tot = 0;
	memset(r, 0, sizeof r);
	for (int i = s; i <= t; ++i) g[i].clear();
	for (int cat = m + 1; cat < t; ++cat)
	{
		int c; cin >> c;
		g[cat].push_back(t);
		g[t].push_back(cat);
		r[cat][t] = c;
		tot += c;
	}
	for (int prob = 1; prob <= m; ++prob)
	{
		int x; cin >> x;
		for (int i = 0, y; i < x; ++i)
			cin >> y,
			g[prob].push_back(y + m),
			g[y + m].push_back(prob),
			r[prob][y + m] = inf;
		g[s].push_back(prob);
		g[prob].push_back(s);
		r[s][prob] = 1;
	}
}

void augment(int u, int bottleneck)
{
	if (u == s)
	{
		f = bottleneck;
		return;
	} else if (p[u] != -1)
	{
		augment(p[u], min(bottleneck, r[p[u]][u]));
		r[u][p[u]] += f;
		r[p[u]][u] -= f;
	}
}

void flowMatching()
{
	int maxflow = 0;
	while (true)
	{
		f = 0;
		for (int u = 0; u <= t; ++u) p[u] = -1;
		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int u = q.front(); q.pop();
			if (u == t) break;
			for (int v : g[u])
				if (r[u][v] > 0 && p[v] == -1)
					q.push(v), p[v] = u;
		}
		augment(t, inf);
		if (f < 1) break;
		maxflow += f;
	}
	if (maxflow != tot)
		cout << 0 << '\n';
	else
	{
		cout << 1 << '\n';
		for (int cat = m + 1; cat < t; ++cat)
		{
			for (int prob : g[cat])
				if (r[cat][prob] == 1) cout << prob << ' ';
			cout << '\n';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("10092.in", "r", stdin);

	while (cin >> n >> m)
	{
		if (n < 1 && m < 1) return 0;
		fileio();
		flowMatching();
	}
}