#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 115;

int n, buck[N];
vector<pair<int, int> > c;
priority_queue<int, vector<int>, greater<int> > heap[N];

bool chk(int totals)
{
	for (int i = 0; i <= n; ++i)
		while (!heap[i].empty()) heap[i].pop();
	for (int i = 1; i <= totals; ++i)
		heap[0].push(i);
	for (int i = 0; i < (int)c.size(); ++i)
		if (c[i].second > 0)
		{
			if ((int)heap[0].size() < buck[c[i].second]) return false;
			for (int j = 0; j < buck[c[i].second]; ++j)
				heap[c[i].second].push(heap[0].top()), heap[0].pop();
		} else
		{
			while (!heap[-c[i].second].empty())
				heap[0].push(heap[-c[i].second].top()), heap[-c[i].second].pop();
		}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("blist.in", "r", stdin);
	freopen("blist.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int L, R;
		cin >> L >> R >> buck[i];
		c.push_back({L, i});
		c.push_back({R, -i});
	}
	sort(c.begin(), c.end());
	int l = 1, r = 11111, res = 0;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (chk(m)) res = m, r = m - 1;
			else l = m + 1;
	}
	cout << res << '\n';
}