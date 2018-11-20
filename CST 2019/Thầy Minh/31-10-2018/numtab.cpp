#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

int n, m, q, a[1015][1015], h[1015][1015], w[1015][1015], dp[1015][1015], st[1015];
pair<int, int> t[1015][1015];
stack<int> s;
deque<int> x[1015];

void solve()
{
	memset(w, 0, sizeof w);
	for (int i=1; i<=n; i++)
	{
		int top=0;
		st[0]=0;
		x[i].clear();
		for (int j=1; j<=m; ++j)
		{
			while (top>=0&&h[i][st[top]]>=h[i][j]) --top;
			if (top>=0)
				w[i][j]+=(j-st[top]-1);
			st[++top]=j;
		}
		top=0;
		st[0]=m+1;
		for (int j=m; j>=1; --j)
		{
			while (top>=0&&h[i][st[top]]>=h[i][j]) --top;
			if (top>=0)
				w[i][j]+=(st[top]-j-1);
			st[++top]=j;	
		}
		for (int j=1; j<=m; ++j)
			t[i][j]=make_pair(h[i][j], w[i][j]+1);
		sort(t[i]+1, t[i]+m+1);
		for (int j=1; j<=m; ++j)
		{
			while (!x[i].empty())
			{
				if (t[i][x[i].back()].second<=t[i][j].second) x[i].pop_back();
					else break;
			}
			x[i].push_back(j);
		}
	}	
	for (int l=n; l>=1; --l)
		for (int r=l; r<=n; ++r)
		{
			while (!x[r].empty()&&t[r][x[r].front()].first<(r-l+1))
				x[r].pop_front();
			if (!x[r].empty())
				dp[l][r]=max(dp[l][r], (r-l+1)*t[r][x[r].front()].second);
			dp[l][r]=max(dp[l][r], max(dp[l+1][r], dp[l][r-1]));
		}
}

int main()
{
	freopen("numtab.inp", "r", stdin);
	freopen("numtab.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			scanf("%d", &a[i][j]);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			h[i][j]=((a[i][j]==1||a[i][j]==0)?h[i-1][j]+1:(a[i][j]<2));
	solve();
	memset(h, 0, sizeof h);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			h[i][j]=((a[i][j]==1||a[i][j]==2)?h[i-1][j]+1:(a[i][j]>0));
	solve();
	scanf("%d", &q);
	while (q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", dp[l][r]);
	}
	return 0;
}
/*
	using deque technique to find height and width
	sorting (greedy) and push to the deque x
	dp to maintain the optimal result
*/