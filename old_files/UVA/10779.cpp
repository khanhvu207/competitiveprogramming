#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int inf = 2e9;

int n, m, f, s, t;
int has[15][35], r[115][115], p[115];
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

int flow()
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

		augment(t, inf);
		if (f == 0) break;
		maxflow += f;
	}
	return maxflow;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; ++T)
	{
		memset(r, 0, sizeof r);
		memset(has, 0, sizeof has);
		for (int i = 0; i < 115; ++i) g[i].clear();

		cin >> n >> m;
		for (int i = 1, k; i <= n; ++i)
		{
			cin >> k;
			for (int j = 0, x; j < k; ++j)
			{
				cin >> x;
				++has[i][x];
			}
		}

		--n;
		s = 0, t = n + m + 1;
		
		for (int i = 1; i <= m; ++i)
		{
			r[s][i] = has[1][i],
			g[s].push_back(i),
			g[i].push_back(s);

			r[i][t] = 1;
			g[i].push_back(t);
			g[t].push_back(i);
		}
		for (int i = 1; i <= m; ++i)
			for (int j = m + 1; j <= n + m; ++j)
			{
				r[i][j] = !has[j - m + 1][i];
				r[j][i] = (has[j - m + 1][i] > 0) * (has[j - m + 1][i] - 1);
				g[i].push_back(j);
				g[j].push_back(i);
			}

		cout << "Case #" << T << ": " << flow() << '\n';
	}
}