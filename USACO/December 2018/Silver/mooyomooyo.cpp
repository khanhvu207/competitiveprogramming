#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int N = 115;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, k, cnt;
char c[N][N];
bool vis[N][N];
queue<pair<int, int> > q;

void DFS(int x, int y)
{
	vis[x][y] = true;
	q.push({x, y});
	for (int i = 0; i < 4; ++i)
	{
		int X = x + dx[i];
		int Y = y + dy[i];
		if (X < 0 || X >= n || Y < 0 || Y >= 10 || c[X][Y] != c[x][y] || vis[X][Y]) continue;
		DFS(X, Y);
	}
}

bool eraseHaybales()
{
	bool flag = false;
	memset(vis, false, sizeof vis);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 10; ++j)
			if (c[i][j] != '0' && !vis[i][j]) 
			{
				while (!q.empty()) q.pop();
				DFS(i, j);
				if ((int)q.size() >= k) 
				{
					flag = true;
					while (!q.empty()) 
						c[q.front().first][q.front().second] = '0', q.pop();
				}
			}
	return flag;
}

void gravity()
{
	for (int col = 0; col < 10; ++col)
	{
		queue<char> b;
		for (int i = n - 1; i >= 0; --i)
			if (c[i][col] != '0') b.push(c[i][col]);
		int j = n - 1;
		while (!b.empty())
		{
			c[j][col] = b.front(); b.pop();
			--j;
		}
		for (int i = j; i >= 0; --i)
			c[i][col] = '0';
	}
}

void print()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 10; ++j)
			cout << c[i][j];
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 10; ++j)
			cin >> c[i][j];
	
	while (true)
	{
		if (!eraseHaybales()) break;
		gravity();
	}
	print();
}