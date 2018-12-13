#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int inf = 1e9;

string str;
int n, node, p;
int f[20015][3], r[20015][3];
vector<int> g[20015];


void graph (int u)
{
	int child = str[p] - '0';
	g[u].clear();
	for (int i = 0; i < child; ++i)
	{
		++node; ++p;
		g[u].push_back(node);
		graph(node);
		
	}
}

void dfs (int u, int color)
{
	if (f[u][color] != -1) return;
	if (g[u].empty())
	{
		f[u][color] = r[u][color] = !color;
		return;
	}

	f[u][color] = 0;
	r[u][color] = inf;

	if ((int)g[u].size() == 1)
	{
		for (int i = 0; i < 3; ++i)
			if (color != i)
			{
				dfs(g[u][0], i);
				f[u][color] = max(f[u][color], f[g[u][0]][i]);
				r[u][color] = min(r[u][color], r[g[u][0]][i]);
			}
	} else
	{
		int col1 = -1, col2;
		for (int i = 0; i < 3; ++i)
		{
			if (i != color && col1 < 0) col1 = i;
			if (i != color && i != col1) col2 = i;
		}
		dfs(g[u][0], col1);
		dfs(g[u][1], col2);
		dfs(g[u][0], col2);
		dfs(g[u][1], col1);

		f[u][color] = max(f[g[u][0]][col1] + f[g[u][1]][col2], f[g[u][0]][col2] + f[g[u][1]][col1]); 
		r[u][color] = min(r[g[u][0]][col1] + r[g[u][1]][col2], r[g[u][0]][col2] + r[g[u][1]][col1]); 
	}	
	f[u][color] += !color;
	r[u][color] += !color;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> str;
		n = (int)str.size();

		node = p = 0;
		graph(0);

		int a = 0, b = inf;
		for (int i = 0; i <= node; ++i)
			for (int j = 0; j < 3; ++j)
				f[i][j] = -1;

		for (int i = 0; i < 3; ++i)
		{
			dfs(0, i);
			a = max(a, f[0][i]);
			b = min(b, r[0][i]);
		}
		cout << a << ' ' << b << '\n';
	}
}