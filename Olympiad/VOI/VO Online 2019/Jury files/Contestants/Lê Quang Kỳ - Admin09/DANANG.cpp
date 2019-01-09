#include <bits/stdc++.h>
using namespace std;

struct TE {int v[2], id[2]; long long w;};
typedef pair<int, int> ii;

struct TH
{
    long long du, prew, u, id;
    inline bool operator < (const TH& x) const
    {
        return (du > x.du) || (du == x.du && prew > x.prew);
    }
};

int n, m;
long long D;
TE e[200001];
vector<int> g[200001];
vector<long long> d[200001];
vector<bool> visitted[200001];

inline int getV(long long u, int id)
{
	if (u == e[id].v[0]) return 1;
	else return 0;
}

void Dijkstra()
{
	priority_queue<TH> H;
	H.push({0, 0, 1, 0});
	while (!H.empty())
	{
	    TH u = H.top();
		H.pop();
		if (u.du > d[u.u][u.id]) continue;

		for (int i = 0; i < g[u.u].size(); i++)
		{
			TE edge = e[g[u.u][i]];
			int id = getV(u.u, g[u.u][i]);
			long long& dv = d[edge.v[id]][edge.id[id]];
			if (edge.w >= u.prew && (!visitted[edge.v[id]][edge.id[id]] || dv > u.du + edge.w))
			{
				dv = u.du + edge.w;
				visitted[edge.v[id]][edge.id[id]] = true;
				visitted[edge.v[1-id]][edge.id[1-id]] = true;
				H.push({dv, edge.w+D, edge.v[id], edge.id[id]});
			}
		}
	}
}

int main()
{
	freopen("DANANG.INP", "r", stdin);
	freopen("DANANG.OUT", "w", stdout);
	scanf("%d%d%lli", &n, &m, &D);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%lli", &e[i].v[0], &e[i].v[1], &e[i].w);
		g[e[i].v[0]].push_back(i); g[e[i].v[1]].push_back(i);
		d[e[i].v[0]].push_back(0); visitted[e[i].v[0]].push_back(false);
		e[i].id[0] = d[e[i].v[0]].size()-1;
		d[e[i].v[1]].push_back(0); visitted[e[i].v[1]].push_back(false);
		e[i].id[1] = d[e[i].v[1]].size()-1;
	}
	Dijkstra();
	long long res = 2e18;
	for (int i = 0; i < g[n].size(); i++)
		if (visitted[n][i])
			res = min(res, d[n][i]);
	if (res < 2e18) cout << res;
	else cout << -1;
}
