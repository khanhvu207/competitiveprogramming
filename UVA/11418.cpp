#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

int n, f, s = 0, t = 27;
vector<int> g[115];
int r[115][115], p[115];
string name[115][115];

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
		for (int i = 0; i <= t + n; ++i) p[i] = -1;
		queue<int> q;
		q.push(s);

		while (!q.empty())
		{
			int u = q.front(); q.pop();
			if (u == t) break;
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

void convert(string &s)
{
	for (int i = 0; i < (int)s.size(); ++i)
		if (s[i] <= 'Z') 
			s[i] = s[i] + 32;
	s[0] = toupper(s[0]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);

	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; ++T)
	{
		for (int i = 0; i < 115; ++i) g[i].clear();
		memset(r, 0, sizeof r);
		cin >> n;

		for (int i = 1, k; i <= n; ++i)
		{
			cin >> k;
			r[s][i + t] = 1;
			g[s].push_back(i + t);
			g[i + t].push_back(s);

			r[i][t] = 1;
			g[i].push_back(t);
			g[t].push_back(i);

			for (int j = 0; j < k; ++j)
			{
				string str;
				cin >> str;
				convert(str);
				int letter = str[0] - 'A' + 1;
				if (letter <= n)
				{
					r[i + t][letter] = 1;
					g[i + t].push_back(letter);
					g[letter].push_back(i + t);
					name[i + t][letter] = str;
				}
			}
		}
		
		maxflow();

		cout << "Case #" << T << ":\n";
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (r[i][j + t] != 0)
				{
					cout << name[j + t][i] << '\n';
					break;
				}
	}
}