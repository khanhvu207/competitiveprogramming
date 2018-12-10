#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int n;
bool a[100015];
set<int> s;

void Input()
{
	cin >> n;
	for (int i=0, x; i<n; ++i)
		cin >> x, a[x] = true;
}

void Solve()
{
	for (int i=1; i<=2*n; ++i)
		if (!a[i]) s.insert(i);
	int res = 0;
	for (int i=1; i<=2*n; ++i)
		if (a[i])
		{
			set<int>::iterator it = s.upper_bound(i);
			if (it==s.end()) continue;
			++res;
			s.erase(it);
		}
	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	Input();
	Solve();
}