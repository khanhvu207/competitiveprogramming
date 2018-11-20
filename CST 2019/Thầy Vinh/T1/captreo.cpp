#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
vector<int> g[1015];
bool vst[1015];
int d[1015];
struct data
{
	int u, c;
	data (int uu, int cc)
	{
		this -> u = uu;
		this -> c = cc;
	}
	bool operator < (const data &r) const
	{
		return c > r.c;
	}
};
priority_queue<data> q;

void Dijkstra()
{
	memset(vst, 0, sizeof vst);
	for (int i = 1; i <= n; i++) d[i] = 1000000000;
	d[n] = 0;
	vst[n] = 1;
	q.push(data(n, d[n]));
	while (!q.empty())
	{
		data T = q.top(); q.pop();
		if (T.c > d[T.u]) continue;
		vst[T.u] = 1;
		for (int i = 0; i < (int)g[T.u].size(); i++)
		{
			int v = g[T.u][i];
			int cycle = (T.u - v) * 4;
			int wait = cycle - (T.c % cycle);
			if (wait == cycle) wait = 0;
			if (!vst[v] && T.c + wait + (T.u - v) * 2 < d[v])
			{
				d[v] = T.c + wait + (T.u - v) * 2;
				q.push(data(v, d[v]));
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("captreo.inp", "r", stdin);
    freopen("captreo.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++)
    	cin >> u >> v,
    	g[v].push_back(u);
    Dijkstra();
    cout << d[1];
    return 0;
}
