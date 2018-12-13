#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

map<string, int> mp;
int n, m, s, t, f;
int r[115][115], p[115];
vector<int> g[115];

void augment (int u, int fx)
{
	if (u == s)
	{
		f = fx;
		return;
	} else if (p[u] != -1)
	{
		augment(p[u], min(fx, r[p[u]][u]));
		r[p[u]][u] -= f;
		r[u][p[u]] += f;
	}
}

int maxflow()
{
	int maxflow = 0;
	while (true)
	{
		f = 0;
		for (int i = 0; i <= t; ++i) p[i] = -1;
		queue<int> q;
		q.push(s);

		while (!q.empty())
		{
			int u = q.front(); q.pop();
			for (int v : g[u])
				if (r[u][v] > 0 && p[v] == -1)
					p[v] = u, q.push(v);
		}

		augment(t, 123);
		if (f == 0) break;
		maxflow += f;
	}
	return maxflow;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	mp["XS"] = 1; 
	mp["S"] = 2; 
	mp["M"] = 3; 
	mp["L"] = 4; 
	mp["XL"] = 5; 
	mp["XXL"] = 6; 

	int tc;
	cin >> tc;
	while (tc--)
	{
		memset(r, 0, sizeof r);
		for (int i = 0; i < 115; ++i) g[i].clear();

		cin >> n >> m;
		s = 0, t = m + 7;
		
		for (int i = 1; i <= 6; ++i)
			r[s][i] = n / 6,
			g[s].push_back(i),
			g[i].push_back(s);
		for (int i = 1; i <= m; ++i)
		{
			string a, b;
			cin >> a >> b;
			r[mp[a]][i + 6] = 123;
			r[mp[b]][i + 6] = 123;
			r[i + 6][t] = 1;
			
			g[mp[a]].push_back(i + 6);
			g[i + 6].push_back(mp[a]);
			g[mp[b]].push_back(i + 6);
			g[i + 6].push_back(mp[b]);
			g[i + 6].push_back(t);
			g[t].push_back(i + 6);
		}

		cout << (maxflow() == m ? "YES\n" : "NO\n");
	}
}