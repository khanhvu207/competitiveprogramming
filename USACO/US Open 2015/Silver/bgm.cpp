#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;
const char c[7]={'B', 'E', 'S', 'I', 'G', 'O', 'M'};
int n, t[7][3];
vector<int> g[200];
long long dp[10][7][7][7];

void Input()
{
	cin >> n;
	for (int i=0; i<n; ++i)
	{
		char x; int v;
		cin >> x >> v;
		g[x-'A'].push_back(v);		
	}
}

long long rec(int i, int x, int y, int z)
{
	if (dp[i][x][y][z]!=-1) return dp[i][x][y][z];
	if (i==7)
		return (x*y*z)%7==0;
	dp[i][x][y][z]=0;
	for (int j=0; j<(int)g[c[i]-'A'].size(); ++j)
	{
		int v=g[c[i]-'A'][j];
		dp[i][x][y][z]+=rec(i+1, (x+v*t[i][0]+7*111111)%7, (y+v*t[i][1]+7*111111)%7, (z+v*t[i][2]+7*111111)%7);
	}
	return dp[i][x][y][z];
}

void Solve()
{
	memset(dp, -1, sizeof dp);
	cout << rec(0, 0, 0, 0);
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	t[0][0]=1;
	t[1][0]=2;
	t[1][1]=1;
	t[2][0]=2;
	t[2][1]=1;
	t[3][0]=1;
	t[4][1]=1;
	t[5][1]=1;
	t[5][2]=2;
	t[6][2]=1;
	freopen("bgm.in", "r", stdin);
	freopen("bgm.out", "w", stdout);
	Input();
	Solve();
}