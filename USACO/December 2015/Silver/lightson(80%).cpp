#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define x first
#define y second
typedef pair<int, int> ii;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
bool vst[115][20015], light[115][20015];
vector<ii> g[115][20015];

void Input()
{
	cin >> n >> m;
	for (int i=0, lx, ly, rx, ry; i<m; ++i)
	{
		cin >> lx >> ly >> rx >> ry;
		g[lx][ly].push_back(ii(rx, ry));
	}
}

void Solve()
{
	queue<ii> q;
	q.push(ii(1, 1));
	vst[1][1] = true;
	int res = 1;
	while (!q.empty())
	{
		ii f = q.front(); q.pop();
		for (int i=0; i<(int)g[f.x][f.y].size(); ++i)
		if (!light[g[f.x][f.y][i].x][g[f.x][f.y][i].y])
		{
			++res;
			light[g[f.x][f.y][i].x][g[f.x][f.y][i].y] = true;
			for (int j=0; j<4; ++j)
			{
				int X = g[f.x][f.y][i].x+dx[j];
				int Y = g[f.x][f.y][i].y+dy[j];
				if (X<1 || X>n || Y<1 || Y>m) continue;
				if (vst[X][Y])
					q.push(ii(X, Y));
			}
		}
		for (int i=0; i<4; ++i)
		{
			int X = f.x+dx[i];
			int Y = f.y+dy[i];
			if (X<1 || X>n || Y<1 || Y>m || vst[X][Y] || !light[X][Y]) continue;
			vst[X][Y] = true;
			q.push(ii(X, Y));
		}
	}
	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	Input();
	Solve();
}

// 5 10
// 3 5 1 2
// 1 1 1 2
// 1 1 2 2
// 3 3 1 1
// 4 1 3 2
// 1 2 1 3
// 2 3 4 3
// 1 1 2 1
// 5 1 2 1
// 1 1 3 2
