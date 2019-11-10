#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int inf = 1e9;
const int maxn = 1005;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, g[maxn][maxn], d[maxn][maxn][5][2];
bool vst[maxn][maxn][5][2];

struct Node {
	int x, y, dist, pv;
	bool orange;
	Node(int xx, int yy, int d, int p, bool o) : x(xx), y(yy), dist(d), pv(p), orange(o) {}
	bool operator < (const Node& r) const {
		return dist > r.dist;
	}
};

bool isValid(int x, int y, bool orange) {
	if (x < 1 || x > n || y < 1 || y > m) return false;
	if (!orange && g[x][y] == 3) return false;
	if (g[x][y] == 0) return false;
	return true;
}

int shortestPath() {
	int res = inf;
	priority_queue<Node> q;
	
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int k = 0; k < 4; ++k)
				d[i][j][k][0] = inf, d[i][j][k][1] = inf;
	
	q.push(Node(1, 1, 0, 4, false));
	d[1][1][4][false] = 0;
	
	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int dist = q.top().dist;
		int p = q.top().pv;
		bool orange = q.top().orange;
		q.pop();
		if (dist > d[x][y][p][orange]) continue;
		
		if (x == n && y == m) {
			res = min(res, dist);
		}
		
		vst[x][y][p][orange] = true;
		int nxtx, nxty;
		orange |= g[x][y] == 2;
		if (g[x][y] == 4) orange = false;
		
		if (g[x][y] == 4) {
			nxtx = x + dx[p];
			nxty = y + dy[p];
			if (isValid(nxtx, nxty, orange) && !vst[nxtx][nxty][p][orange] && dist + 1 < d[nxtx][nxty][p][orange]) {
				d[nxtx][nxty][p][orange] = dist + 1;
				q.push(Node(nxtx, nxty, dist + 1, p, orange));
				continue;
			}
		}
		
		for (int i = 0; i < 4; ++i) {
			nxtx = x + dx[i];
			nxty = y + dy[i];
			if (isValid(nxtx, nxty, orange) && !vst[nxtx][nxty][i][orange] && dist + 1 < d[nxtx][nxty][i][orange]) {
				d[nxtx][nxty][i][orange] = dist + 1;
				q.push(Node(nxtx, nxty, dist + 1, i, orange));
			}
		}
	}
	
	if (res == inf) res = -1;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) 
			cin >> g[i][j];
	
	cout << shortestPath();
	
	return 0;
}
