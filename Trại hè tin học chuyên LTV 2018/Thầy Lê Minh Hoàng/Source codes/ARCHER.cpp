#include <bits/stdc++.h>
using namespace std;

struct Tpoint
{
	long long x, y, z;
};

struct Tvector
{
	long long x, y, z;
	bool operator < (const Tvector &a) const 
	{
		if (a.x == x)
		{
			if (a.y == y) return a.z < z;
			else return a.y < y;
		} else return a.x < x;
	}
};

int n;
long long res = 1, mxz = -1e18, mnz = 1e18;
Tpoint b[2005];
map<Tvector, long long> M;

int main()
{
	freopen("ARCHER.INP", "r", stdin);
	freopen("ARCHER.OUT", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> b[i].x >> b[i].y >> b[i].z, mxz = max(mxz, b[i].z), mnz = min(mnz, b[i].z);
	if (mxz != mnz) res = 2; else res = 1;

	for (int A = 0; A < n; A++) {
		long long CZ = 0, R = 0, sum = 0;
		M.clear();
		for (int B = 0; B < n; B++) 
		{
			if (B == A) continue;
			int vx = b[B].x - b[A].x;
			int vy = b[B].y - b[A].y;
			int vz = b[B].z - b[A].z;
			if (vx == 0 && vy == 0 && vz == 0) CZ++;
			if (vz <= 0) continue;
			int t = __gcd(abs(vx), __gcd(abs(vy), abs(vz)));
			vx /= t, vy /= t, vz /= t;
			Tvector T; T.x = vx, T.y = vy, T.z = vz;
			if (!M.count(T)) M[T] = 1;
			else M[T]++, R = max(R, M[T]);
		}
		sum = 1 + CZ + R;
		res = max(res, sum);
	}
	cout << res << '\n';
}