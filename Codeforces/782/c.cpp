#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, cnt, deg[N], color[N];
vector<int> g[N];

void dfs(int u, int p, int x) {
	color[u] = x % cnt;
	for (int v : g[u]) 
		if (v != p) {
			++x;
			if (x % cnt == color[p]) ++x;
			dfs(v, u, x);
		}
}

int main() {
#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		++deg[u];
		++deg[v];
	}	
	for (int i = 1; i <= n; ++i) cnt = max(cnt, deg[i]);
	++cnt;
	dfs(1, -1, 0);
	cout << cnt << '\n';
	for (int i = 1; i <= n; ++i) cout << color[i] + 1 << ' '; 
}