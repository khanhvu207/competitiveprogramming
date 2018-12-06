#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, e;
int w[1111], d[1111], a[1111], dp[1111];
vector<int> g[1111];

void Input()
{
	cin >> n >> e;
	for (int u=1; u<=n; ++u)
	{
		int m;
		cin >> w[u] >> m;
		for (int j=0, v; j<m; ++j)
			cin >> v,
			g[u].push_back(v),
			g[v].push_back(u);
	}
}

void Solve()
{
	int res=0;
	for (int u=1; u<=n; ++u)
		a[u]=u;
	sort(a+1, a+n+1, [&](int l, int r){ return w[l]<w[r]; });
	for (int i=1, u; i<=n; ++i)
	{
		u=a[i];
		for (int v=1; v<=n; ++v) d[v]=-1;
		d[u]=0;
		queue<int> q; q.push(u);
		while (!q.empty())
		{
			int t=q.front(); q.pop();
			for (int v : g[t])
				if (d[v]==-1)
				{
					d[v]=d[t]+1;
					q.push(v);
				}
		}
		dp[u]=w[u];
		for (int j=1; j<i; ++j)
			if (d[a[j]]!=-1)
				dp[u]=max(dp[u], w[u]+dp[a[j]]-e*d[a[j]]);
		res=max(res, dp[u]);
	}
	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("buffet.in", "r", stdin);
	freopen("buffet.out", "w", stdout);
	Input();
	Solve();
}