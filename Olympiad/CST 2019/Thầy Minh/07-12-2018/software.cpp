#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int n, a[111], b[111];
int x, y, best=2e9, opt=2e9;
long long mx, my, ansx, ansy;
vector<int> va, vb, ra, rb;

void Input()
{
	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	for (int i=0; i<n; ++i) cin >> b[i];
}

void randomy(int i, int sx, int sy, long long maskx, long long masky)
{
	if (i>=n)
	{
		if (max(sx, sy)<best)
			best=max(sx, sy),
			ansx=maskx, 
			ansy=masky;
		return;
	}
	int token=rand()%2;
	if (token&1)
	{
		randomy(i+1, sx, sy+b[i], maskx, masky|(1ll<<(i*1ll)));
        
	} else
	{
		randomy(i+1, sx+a[i], sy, maskx|(1ll<<(i*1ll)), masky);
	}
}

void rec(int i, int r, int sx, int sy, long long maskx, long long masky)
{
	if (i>r)
	{
		if (r==n-1)
		{
			if (max(sx, sy)<best)
				best=max(sx, sy),
				ansx=maskx,
				ansy=masky;
		} else
		{
			if (max(sx, sy)<opt)
				x=sx, y=sy, mx=maskx, my=masky, opt=max(sx, sy);
		}
		return;
	}
	rec(i+1, r, sx+a[i], sy, maskx|(1ll<<i), masky);
	rec(i+1, r, sx, sy+b[i], maskx, masky|(1ll<<i));
}

void Solve()
{
	x=1e9, y=1e9;
	rec(0, n/2-1, 0, 0, 0, 0);
	rec(n/2, n-1, x, y, mx, my);
	cout << best << '\n';
	for (long long i=0; i<n; ++i)
		if (ansx&(1ll<<i)) cout << i+1 << ' ';
	cout << '\n';
	for (long long i=0; i<n; ++i)
		if (ansy&(1ll<<i)) cout << i+1 << ' ';
}

void darkmagic()
{
	srand(time(NULL));
	while (clock()<0.777*CLOCKS_PER_SEC)
	{
		randomy(0, 0, 0, 0, 0);
	}
	cout << best << '\n';
	for (long long i=0; i<n; ++i)
		if (ansx&(1ll<<i)) cout << i+1 << ' ';
	cout << '\n';
	for (long long i=0; i<n; ++i)
		if (ansy&(1ll<<i)) cout << i+1 << ' ';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("software.inp", "r", stdin);
	freopen("software.out", "w", stdout);
	Input();
	if (n<41) Solve();
		else darkmagic();
}
