#include <bits/stdc++.h>
using namespace std;
const int N = 5015;
const int inf = 2e9;

struct node {
	int ans, u, fuel;
	node(int anss, int uu, int fuell) {
		this -> ans = anss;
		this -> u = uu;
		this -> fuel = fuell;
	}
	bool operator < (const node &r) const {
		return ans > r.ans;
	}
};
priority_queue<node> heap;
int n, m;
int c[N], d[N], f[N][N];
vector<int> g[N];
bool vis[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i] >> d[i];
	}
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			f[i][j] = inf;
	f[1][d[1]] = c[1];
	heap.push(node(c[1], 1, d[1]));
	int res = inf;
	while (!heap.empty()) {
		int cost = heap.top().ans;
		int u = heap.top().u;
		int fuel = heap.top().fuel;
		heap.pop();
		if (cost > f[u][fuel] || fuel < 1) continue;
		vis[u][fuel] = true;
		if (u == n) 
			res = min(res, cost);
		for (int v : g[u]) {
			if (!vis[v][d[v]] && cost + (v != n ? c[v] : 0) < f[v][d[v]]) {
				f[v][d[v]] = cost + (v != n ? c[v] : 0);
				heap.push(node(f[v][d[v]], v, d[v]));
			}
			if (!vis[v][fuel - 1] && cost < f[v][fuel - 1]) {
				f[v][fuel - 1] = cost;
				heap.push(node(f[v][fuel - 1], v, fuel - 1));
			}
		}
	}
	cout << res;
}