#include <bits/stdc++.h>
using namespace std;

struct TPoint {long long x, y;};
struct THCN {TPoint A, C;};

int n;
THCN a[100001];
bool sub2 = true;

inline bool cmpx(const THCN& a, const THCN& b)
{
	return a.A.x < b.A.x;
}

inline bool cmpy(const THCN& a, const THCN& b)
{
	return a.A.y < b.A.y;
}

int main()
{
	freopen("TIGERSUGAR.INP", "r", stdin);
	freopen("TIGERSUGAR.OUT", "r", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lli%lli%lli%lli", &a[i].A.x, &a[i].A.y, &a[i].C.x, &a[i].C.y);
		if (a[i].A.x != a[i].C.x || a[i].A.y != a[i].C.y) sub2 = false;
	}
	if (sub2)
	{
		sort(a+1, a+n+1, cmpx);
		long long x = a[(n+1)/2].A.x;
		sort(a+1, a+n+1, cmpy);
		long long y = a[(n+1)/2].A.y;
		long long res = 0;
		for (int i = 1; i <= n; i++)
			res += abs(x - a[i].A.x) + abs(y - a[i].A.y);
		cout << res;
		cout << "\n" << x << ' ' << y << "\n";
		for (int i = 1; i <= n; i++)
			cout << a[i].A.x << ' ' << a[i].A.y << "\n";
	}
}
