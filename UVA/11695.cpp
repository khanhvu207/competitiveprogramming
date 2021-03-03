#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int n;

vector<int> diameter(const vector<vector<pair<int, bool> > > &g, int start) {
	queue<int> q;
	vector<int> p((int)g.size() + 15);
	vector<bool> vis((int)g.size() + 15, false);
	q.push(start);
	vis[start] = true;
	int far = start;
	
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		far = u;
		for (const pair<int, bool> &i : g[u]) {
			if (!i.second || vis[i.first])
				continue;
			vis[i.first] = true;
			q.push(i.first);
		}
	}

	q.push(far);
	vis.assign((int)g.size() + 15, false);
	vis[far] = true;
	p[far] = -1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		far = u;
		for (const pair<int, bool> &i : g[u]) {
			if (!i.second || vis[i.first]) 
				continue;
			vis[i.first] = true;
			p[i.first] = u;
			q.push(i.first);
		}
	}

	vector<int> path;
	while (far != -1) {
		path.emplace_back(far);
		far = p[far];
	}

	return path;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<vector<pair<int, bool> > > g(n + 15);
		for (int i = 0, u, v; i < n - 1; ++i) {
			cin >> u >> v;
			g[u].emplace_back(v, true);
			g[v].emplace_back(u, true);
		}
		vector<int> longestpath = diameter(g, 1);

		int best = n, c1 = 0, c2 = 0, add1 = 0, add2 = 0;
		for (int i = 1; i < (int)longestpath.size(); ++i) {
			int u = longestpath[i - 1];
			int v = longestpath[i];
			pair<int, bool> *cutedge1;
			pair<int, bool> *cutedge2;
			for (pair<int, bool> &i : g[u])
				if (i.first == v) {
					cutedge1 = &i;
					break;
				}
			for (pair<int, bool> &i : g[v])
				if (i.first == u) {
					cutedge2 = &i;
					break;
				}
			cutedge1 -> second = false;
			cutedge2 -> second = false;
			vector<int> lefttree = diameter(g, u);
			vector<int> righttree = diameter(g, v);
			int d = max(ceil((lefttree.size() - 1) / 2.0) + ceil((righttree.size() - 1) / 2.0) + 1.0, max(lefttree.size() - 1.0, righttree.size() - 1.0));
			if (d < best) {
				best = d;
				c1 = u;
				c2 = v;
				add1 = lefttree[(int)lefttree.size() / 2];
				add2 = righttree[(int)righttree.size() / 2];
			}
			cutedge1 -> second = true;
			cutedge2 -> second = true;
		}
		cout << best << '\n';
		cout << c1 << ' ' << c2 << '\n';
		cout << add1 << ' ' << add2 << '\n';
	}
}