#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int n, res = 0;
stack<pair<int, int> > s;
vector<long long> d, cnt;
vector<pair<long long, long long> > info;
vector<pair<long long, long long> > swp;

bool cmp (const pair<long long, long long> &L, const pair<long long, long long> &R)
{
	if (L.first == R.first)
	{
		if (L.second * R.second < 0) return L.second < 0;
		if (L.second < 0 && R.second < 0) return info[-L.second].first > info[-R.second].first;
		if (L.second > 0 && R.second > 0) return info[L.second].second > info[R.second].second;
	} 
	return L.first < R.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("circles.inp", "r", stdin);
	freopen("circles.out", "w", stdout);

	cin >> n;
	info.resize(n + 3);
	d.resize(n + 3);

	for (int i = 1; i <= n; ++i)
	{
		long long C, R;
		cin >> C >> R;
		swp.push_back({C - R, i});
		swp.push_back({C + R, -i});
		info[i] = {C - R, C + R};
	}

	sort(swp.begin(), swp.end(), cmp);

	for (int i = 0; i < 2 * n; ++i)
		if (swp[i].second > 0) 
			s.push({swp[i].second, 0});
		else
		{
			pair<int, int> t = s.top(); s.pop();
			long long k = (info[t.first].second - info[t.first].first + 1);
			res += 1 + (k == d[t.first] - t.second + 1);
			if (!s.empty()) d[s.top().first] += k, ++s.top().second;
		}
	cout << res + 1;
}