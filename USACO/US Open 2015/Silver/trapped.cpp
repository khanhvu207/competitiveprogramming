#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const long long inf=1e18;

int n, b, R;
int id[100015];
long long s[100015], p[100015], suff[100015], pref[100015];
vector<pair<long, long> > a;

void Input()
{
	cin >> n >> b;
	for (int i=1; i<=n; ++i)
	{
		long long S, P;
		cin >> S >> P;
		a.push_back({P, S});
	}
	sort(a.begin(), a.end());
	for (int i=0; i<n; ++i)
	{
		s[i+1]=a[i].second;
		p[i+1]=a[i].first;
		if (p[i+1]<=b) R=i+1;
	}
}

void Solve()
{
	long long res=inf;
	for (int i=R; i>=1; --i)
		suff[i]=max(suff[i+1], p[i]+s[i]);
	pref[R]=inf;
	for (int i=R+1; i<=n; ++i)
		pref[i]=min(pref[i-1], p[i]-s[i]);
	for (int i=R+1; i<=n; ++i)
	{
		int x=lower_bound(p+1, p+n+1, p[i]-s[i])-p;
		if (x<=R) res=min(res, p[i]-suff[x]);
	}
	for (int i=R; i>=1; --i)
	{
		int y=upper_bound(p+1, p+n+1, p[i]+s[i])-p;
		if (!(y==n&&p[y]<=p[i]+s[i])) --y;
		if (y>R) res=min(res, pref[y]-p[i]);
	}
	if (res==inf)
		cout << -1;
	else
		cout << max(0ll, res);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("trapped.in", "r", stdin);
	freopen("trapped.out", "w", stdout);
	Input();
	Solve();
	return 0;
}