#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
using namespace std;
const int N = 65;

int n, deg[N];
list<pair<int, int> > euler;
vector<pair<int, bool> > g[N];

void euler_cycle(list<pair<int, int> >::iterator it, int u) {
	for (auto &i : g[u]) 
		if (i.second) {
			int v = i.first;
			i.second = false;
			for (auto &edge : g[v])
				if (edge.first == u && edge.second) {
					edge.second = false;
					break;
				}
			euler_cycle(euler.insert(it, {v, u}), v);
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);

	int tc;
	cin >> tc;
	for (int c = 1; c <= tc; ++c) {
		if (c != 1) cout << '\n';
		cout << "Case #" << c << '\n';
		for (int i = 0; i < N; ++i) 
			g[i].clear(), deg[i] = 0;

		cin >> n;
		for (int i = 0, u, v; i < n; ++i) {
			cin >> u >> v;
			g[u].emplace_back(v, true);
			g[v].emplace_back(u, true);
			++deg[u];
			++deg[v];
		}

		bool good = true;
		int start = -1;
		for (int i = 1; i <= 50; ++i)
			if (deg[i] % 2) {
				good = false;
				break;
			} else if (deg[i] && start == -1) {
				start = i;
			}

		if (!good) {
			cout << "some beads may be lost\n";
		} else {
			euler.clear();
			euler_cycle(euler.begin(), start);
			for (const auto &i : euler)
				cout << i.first  << ' ' << i.second << '\n';
		}
	}
}