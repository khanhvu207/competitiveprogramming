#include <bits/stdc++.h>
using namespace std;

struct Tpoint
{
	long long x, y;
};

struct Tvector
{
	long long x, y;
};

int n;
Tpoint A, cvh[100005], p[100005];

inline long long Sarea (const Tvector &V)
{
	return (V.x * V.x + V.y * V.y);
}

inline Tvector operator - (const Tpoint &a, const Tpoint &b)
{
	Tvector res;
	res.x = a.x - b.x;
	res.y = a.y - b.y;
	return res;
}

inline long long operator * (const Tvector &a, const Tvector &b)
{
	long long cross = a.x * b.y - a.y * b.x;
	return cross;
}

bool CCW (const Tpoint &A, const Tpoint &B, const Tpoint &C)
{
	return (B - A) * (C - B) > 0;
}

bool cmp(const Tpoint &B, const Tpoint &C)
{
	Tvector u = B - A;
	Tvector v = C - A;
	long long tmp = u * v;
	return (tmp > 0 || (tmp == 0 && Sarea(u) < Sarea(v)));
}

bool cmp_ (const Tpoint &a, const Tpoint &b)
{
	return (a.y < b.y || ((a.y == b.y) && a.x < b.x));
}

void convexhull(int n)
{
    sort(p, p + n, cmp_);
	A = p[0];

	sort(p + 1, p + n, cmp);

	int k = 0;
	for (int i = 0; i < n; i++)
	{
		while (k >= 2 && !CCW(cvh[k - 2], cvh[k - 1], p[i])) k--;
		cvh[k++] = p[i];
	}

	cvh[k] = p[0];
	long long sum = 0;
	for (int i = 0; i <= k; i++)
	{
		Tpoint A = (i ? cvh[i - 1] : cvh[k]);
		Tpoint B = cvh[i];
		sum += (A.x - B.x) * (A.y + B.y);
	}
	cout << (long long) (sum / 2) << '.' << (sum & 1 ? 5 : 0) << '\n';
}

int main()
{
	//ios_base::sync_with_stdio(false); cin.tie(nullptr);
	freopen("CONVEXHULL.INP", "r", stdin);
	freopen("CONVEXHULL.OUT", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
        cin >> p[i].x >> p[i].y;
        if (i>1) convexhull(i+1);
            else cout << "0.0\n";
    }

	return 0;
}
