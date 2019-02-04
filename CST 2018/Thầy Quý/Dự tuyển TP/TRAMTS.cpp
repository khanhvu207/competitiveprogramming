#include <iostream>
#include <vector>

using namespace std;

int n, dp1[10015], dp2[10015], dp3[10015];
vector <int> a[10015];

void solve(int u, int p) {
	int tmp = 0;
	for (int v: a[u])
		if (v != p)
			solve(v, u),
			tmp += dp1[v];
	dp1[u] = n + 1; dp2[u] = 1; dp3[u] = 0;
	for (int v: a[u])
		if (v != p)
			dp1[u] = min(dp1[u], tmp - dp1[v] + dp2[v]),
			dp2[u] += dp3[v], dp3[u] += dp1[v];
	dp1[u] = min(dp1[u], dp2[u]);
}

int main() {
	cin >> n;
	for (int u, v, i = 1; i < n; ++i)
		cin >> u >> v,
		a[u].push_back(v),
		a[v].push_back(u);
	solve(1, 0); cout << dp1[1];
}