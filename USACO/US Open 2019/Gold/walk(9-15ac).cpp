#include <bits/stdc++.h>
using namespace std;
const long long m = 2019201997;
int n, k;
long long M = 1e18;
set<int> s;
vector<int> r, p;
vector<pair<long long, pair<int, int> > > a;

int getroot (int u)
{
	while (p[u] != u)
		p[u] = p[p[u]], u = p[u];
	return u;
}

int main()
{
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	r.resize(n + 15);
	p.resize(n + 15);
	for (long long i = 1; i < n; ++i)
		for (long long j = i + 1; j <= n; ++j)
			a.push_back(make_pair(((2019201913ll * i) + (2019201949ll * j)) % m, make_pair(i, j)));
	for (int i = 1; i <= n; ++i)
		r[i] = 1, p[i] = i, s.insert(i);
	sort(a.begin(), a.end());
	for (int i = 0; i < (int)a.size(); ++i)
	{
		int u = getroot(a[i].second.first);
		int v = getroot(a[i].second.second);
		if (u == v) continue;
		if ((int)s.size() == k)
		{
			M = min(M, a[i].first);
			continue;
		}
		if (r[u] > r[v])
		{
			r[u] += r[v];
			s.erase(v);
			p[v] = u;
		} else
		{
			r[v] += r[u];
			s.erase(u);
			p[u] = v;
		}
	}
	cout << M;
}