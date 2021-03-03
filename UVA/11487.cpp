#include <iostream>
#include <queue>
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int MOD =  20437;

int n;
bool flag;
char a[15][15];
int d[15][15], f[15][15], dist, ways;
pair<int, int> pos[30];

void BFS(char s, char t)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			d[i][j] = -1, f[i][j] = 0;
	int sx = pos[s - 'A'].first;
	int sy = pos[s - 'A'].second;
	int ex = pos[t - 'A'].first;
	int ey = pos[t - 'A'].second;
	d[sx][sy] = 0;
	f[sx][sy] = 1;
	queue<pair<int, int> > q;
	q.push({sx, sy});
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; ++i)
		{
			int X = x + dx[i];
			int Y = y + dy[i];
			if (X < 0 || X >= n || Y < 0 || Y >= n || a[X][Y] == '#') continue;
			if (a[X][Y] != '.' && a[X][Y] != t) continue;
			f[X][Y] = (f[x][y] + f[X][Y]) % MOD;
			if (d[X][Y] == -1)
			{
				d[X][Y] = d[x][y] + 1;
				q.push({X, Y});
			}
		}
		if (x == ex && y == ey) break;
	}
	if (d[ex][ey] == -1) flag = true;
	dist = (dist + d[ex][ey]) % MOD;
	ways = (ways * f[ex][ey]) % MOD;
	a[sx][sy] = '.';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	int tc = 0;
	while (cin >> n)
	{
		if (!n) return 0;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
			{
				char c; cin >> c;
				a[i][j] = c;
				if (c != '.' && c != '#')
					pos[c - 'A'] = {i, j}, ++cnt;
			}
		flag = false;
		dist = 0, ways = 1;
		for (int i = 0; i < cnt - 1; ++i)
		{
			BFS(i + 'A', i + 'A' + 1);
			if (flag) break;
		}
		cout << "Case " << ++tc << ": ";
		if (flag) cout << "Impossible\n";
			else cout << dist << ' ' << ways << '\n';
	}
}