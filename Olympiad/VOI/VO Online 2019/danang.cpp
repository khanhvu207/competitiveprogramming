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
vector<vector<pair<long long, int> > > g;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("danang.inp", "r", stdin);
	freopen("danang.out", "w", stdout);
	cin >> n >> m >> d;
	g.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		long long c;
		cin >> u >> v >> c;
		g[u].push_back({c, v});
		g[v].push_back({c, u});
	}
	for (int i = 1; i <= n; ++i) {
		sort(g[i].begin(), g[i].end());
	}
	heap.push(node(1, -1e9, 0));
	while (!heap.empty()) {
		int u = heap.top().u;
		int prevlen = heap.top().prevL;
		long long C = heap.top().c;
		heap.pop();
		if (u == n) {
			cout << C;
			return 0;
		}
		while (!g[u].empty()) {
			pair<long long, int> x = g[u].back();
			int v = x.second;
			long long len = x.first;
			g[u].pop_back();
			if (len - d >= prevlen) 
				heap.push(node(v, len, C + len));
			else
				break;
		}
	}
	cout << -1;
}