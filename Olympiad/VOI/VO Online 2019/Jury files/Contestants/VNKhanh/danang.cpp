#include <bits/stdc++.h>
using namespace std;
const int N = 200015;
const long long inf = 1e18;

struct node {
	int u, prevL;
	long long c;
	node(int uu, int prevLL, long long cc) {
		this -> u = uu;
		this -> prevL = prevLL;
		this -> c = cc;
	}
	bool operator < (const node &r) const {
		return c > r.c;
	}
};
priority_queue<node> heap;
int n, m, d;
long long f[N];
bool vis[N];
vector<vector<pair<int, int> > > g;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("danang.inp", "r", stdin);
	freopen("danang.out", "w", stdout);
	cin >> n >> m >> d;
	g.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	for (int i = 1; i <= n; ++i)
		f[i] = inf;
	f[1] = 0;
	heap.push(node(1, 0, f[1]));
	while (!heap.empty()) {
		int u = heap.top().u;
		int prevlen = heap.top().prevL;
		long long C = heap.top().c;
		heap.pop();
		if (C > f[u])
			continue;
		vis[u] = true;
		for (const pair<int, int> &x : g[u]) {
			int v = x.first;
			int len = x.second;
			if (!vis[v] && len - d >= prevlen && C + len * 1ll < f[v]) {
				f[v] = C + len * 1ll;
				heap.push(node(v, len, f[v]));
			}
		}
	}
	if (f[n] == inf)
		cout << -1;
	else
		cout << f[n];
}