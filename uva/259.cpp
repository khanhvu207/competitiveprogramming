#include <iostream>
#include <cstdio>
#include <sstream>
#include <queue>
#include <cstring>
using namespace std;
const int inf = 2e9;

string line;
vector<int> g[55];
int r[55][55], p[55], f, s, t, tot;
bool fEnd;

void augment (int u, int bottleneck)
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
	s = 0, t = 37;
	int maxflow = 0;
	for (int comp = 27; comp <= 36; ++comp)
		g[comp].push_back(t), r[comp][t] = 1;
	while (true)
	{
		f = 0;
		for (int i = 0; i <= 37; ++i) p[i] = -1;
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
		if (f == 0) break;
		maxflow += f;
	}
	//cerr << maxflow << ' ' << tot << '\n';
	if (maxflow != tot)
		cout << "!\n";
	else
	{
		for (int comp = 27; comp <= 36; ++comp)
		{
			bool flag = false;
			for (int task = 1; task <= 26; ++task)
				if (r[comp][task] == 1)
				{
					cout << (char)(task + 'A' - 1);
					flag = true;
					break;
				}
			if (!flag) cout << '_';
		}
		cout << '\n';
	}
	for (int u = 0; u < 38; ++u)
		g[u].clear();
	tot = 0;
	memset(r, 0, sizeof r);
}

void fileio()
{
	fEnd = false;
	while (true)
	{
		string a, b, line;
		if (!getline(cin, line))
		{
			fEnd = true; 
			break;
		}
		if (line == "") break;
		stringstream buffer(line);
		buffer >> a >> b;	
	
		int c = a[1] - 48;
		char task = a[0];
		r[0][task - 'A' + 1] = c;
		g[0].push_back(task - 'A' + 1);
		g[task - 'A' + 1].push_back(0);
		tot += c;
		for (int i = 0; i < (int)b.size() - 1; ++i)
			g[task - 'A' + 1].push_back(b[i] - '0' + 27),
			g[b[i] - '0' + 27].push_back(task - 'A' + 1),
			r[task - 'A' + 1][b[i] - '0' + 27] = inf;
	}
}

int main()
{
	//freopen("259.in", "r", stdin);
	//freopen("259.out", "w", stdout);
	while (true)
	{
		fileio();
		flowMatching();
		if (fEnd) break;
	}
}