#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const long long mod=1e9+7;

int n;
char c[555][555];
long long f[2][555][555];

void Input()
{
	cin >> n;
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> c[i][j];
}

void Solve()
{
	for (int i=0; i<n; ++i)
		f[n&1][i][i]=1ll;
	for (int x=n-1; x>=1; --x)
	{
		for (int i=0; i<n; ++i)
			for (int j=0; j<n; ++j)
				f[x&1][i][j]=0;
		for (int a=0; a<n; ++a)
			for (int b=0; b<n; ++b)
			{
				int lx=a, ly=x-1-a;
				int rx=b, ry=2*n-x-rx-1;
				if (ly<0 || ry>=n || c[lx][ly]!=c[rx][ry]) continue;
				f[x&1][a][b]+=f[(x&1)^1][a][b];
				if (a+1<n) f[x&1][a][b]+=f[(x&1)^1][a+1][b];
				if (b-1>=0) f[x&1][a][b]+=f[(x&1)^1][a][b-1];
				if (a+1<n && b-1>=0) f[x&1][a][b]+=f[(x&1)^1][a+1][b-1];
				f[x&1][a][b]%=mod;
			}
	}
	cout << f[1][0][n-1]%mod << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("palpath.in", "r", stdin);
	freopen("palpath.out", "w", stdout);
	Input();
	Solve();
}