#include <bits/stdc++.h>
using namespace std;

const int N = 10015;
int n, m, r[N], p[N];
vector<pair<int, pair<int, int> > > Egdes;

bool joint (int u, int v) {
	while (u != p[u]) p[u] = p[p[u]], u = p[u];
	while (v != p[v]) p[v] = p[p[v]], v = p[v];
	if (u == v)
		return false;
	if (r[u] > r[v])
		r[u] += r[v], p[v] = u;
	else
		r[v] += r[u], p[u] = v;
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 0, u, v, c; i < m; ++i) {
		cin >> u >> v >> c;
		Egdes.push_back({c, {u, v}});
	}

	sort(Egdes.begin(), Egdes.end());
	
	int MST = 0;
	for (int u = 1; u <= n; ++u)
		r[u] = 1, p[u] = u;

	for (int i = 0; i < m; ++i) {
		int U = Egdes[i].second.first;
		int V = Egdes[i].second.second;
		int L = Egdes[i].first;
		if (joint(U, V))
			MST += L;
	}

	//Output tổng giá trị các cạnh của Minimum Spanning Tree.
	cout << MST;
}

//Code này có thể dùng để nộp bài - https://vn.spoj.com/problems/QBMST/