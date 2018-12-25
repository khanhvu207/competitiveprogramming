#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
const int N = 100;

int n, deg[N];
vector<pair<int, bool> > g[N];

void eulerCycle(int s) {
	vector<int> res;
	stack<int> st;
	st.push(s);
	while (!st.empty()) {
		int u = st.top();
		bool flag = false;
		for (auto &i : g[u]) 
			if (i.second) {
				flag = true;
				i.second = false;
				int v = i.first;
				for (auto &edge : g[v])
					if (edge.first == u && edge.second) {
						edge.second = false;
						break;
					}
				st.push(v);
				break;
			}
		if (!flag) {
			res.emplace_back(u);
			st.pop();
		}
	}
	for (int i = 0; i + 1 < (int)res.size(); ++i)
		cout << res[i] << ' ' << res[i + 1] << '\n';
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
		for (int i = 1; i <= 50; ++i) 
			deg[i] = 0, g[i].clear();

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
		for (int u = 1; u <= 50; ++u)
			if (deg[u] & 1) {
				good = false;
				break;
			} else if (deg[u] && start == -1) {
				start = u;
			}
		
		if (!good) {
			cout << "some beads may be lost\n";
			continue;
		}
		eulerCycle(start);
	}
}