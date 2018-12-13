#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;

int s, t;
int d[105015], trace[105015];
vector<int> g[105015];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("trenet.inp", "r", stdin);
	freopen("trenet.out", "w", stdout);
	
	cin >> s >> t;

	int pv = 0;
	for (int r = 1; r <= 317; ++r)
	{
		int len = 1 + 2 * (r - 1);
		for (int i = 1; i <= len; ++i)
		{
			if (i > 1) 
				g[pv + i].push_back(pv + i - 1);
			if (i < len)
				g[pv + i].push_back(pv + i + 1);
			if (r & 1)
			{
				if ((pv + i) & 1)
					g[pv + i].push_back(pv + i + r * 2);
				else
					g[pv + i].push_back(pv + i - (r - 1) * 2);
			} else
			{
				if ((pv + i) & 1)
					g[pv + i].push_back(pv + i - (r - 1) * 2);
				else
					g[pv + i].push_back(pv + i + r * 2);
			}
		}
		pv += len;
	}

	memset(d, -1, sizeof d);
	queue<int> q;
	q.push(s);
	d[s] = 0;
	trace[s] = -1;
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		if (u == t) break;
		for (int i = 0; i < (int)g[u].size(); ++i)
			if (d[g[u][i]] == -1)
			{
				d[g[u][i]] = d[u] + 1;
				trace[g[u][i]] = u;
				q.push(g[u][i]);
			}
	}
	vector<int> res;
	while (trace[t] != -1)
	{
		res.push_back(t);
		t = trace[t];
	}
	res.push_back(t);
	cout << (int)res.size() - 1 << '\n';
	for (int i = (int)res.size() - 1; i >= 0; --i)
		cout << res[i] << '\n';
}