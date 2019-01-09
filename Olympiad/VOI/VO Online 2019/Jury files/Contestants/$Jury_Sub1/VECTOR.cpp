#include <bits/stdc++.h>

using namespace std;

vector<int> factor(int x) {
	vector<int> res;
	for (int f = 2; f <= x; ++f) {
		if (x % f == 0) {
			res.push_back(f);
			while (x % f == 0) x /= f;
		}
	}
	return res;
}

set<int> f;
map< pair<int, int>, pair<int, int> > possible; // mapping (a, b) -> (transform_type, p)
int a = 1, b = 1;

inline void dfs(int u, int v, int transform_type, int transform_arg) {
	if (u > a * a * b * b || v > a * a * b * b) return;
	if (possible.count({u, v})) return;
	possible[{u, v}] = {transform_type, transform_arg};
	for (int p : f) {
		if (v % (p * p) == 0) dfs(u * p, v / (p * p), 0, p);
		dfs(u, v * p, 1, p);
		if (u % (p * p) == 0) dfs(u / (p * p), v, 2, p);
	}
}

void bfs() {
	queue< pair<int, int> > Q;
	Q.push({a, b});

	auto push_queue = [&Q] (int u, int v, int transform_type, int transform_arg) {
		if (u > a * a * b * b || v > a * a * b * b) return;
		if (possible.count({u, v})) return;
		possible[{u, v}] = {transform_type, transform_arg};
		Q.push({u, v});
	};

	while (!Q.empty()) {
		int u = Q.front().first;
		int v = Q.front().second;
		Q.pop();
		for (int p : f) {
			if (v % (p * p) == 0) push_queue(u * p, v / (p * p), 0, p);
			push_queue(u, v * p, 1, p);
			if (u % (p * p) == 0) push_queue(u / (p * p), v, 2, p);
		}
	}
}

int main() {
#ifdef THEMIS
	freopen("VECTOR.INP", "r", stdin);
	freopen("VECTOR.OUT", "w", stdout);
#endif
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int p; cin >> p;
		a *= p;
		for (int v : factor(p)) {
			f.insert(v);
		}
	}
	
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int q; cin >> q;
		b *= q;
		for (int v : factor(q)) {
			f.insert(v);
		}
	}

	//dfs(a, b, -1, -1);
	bfs();

	int ans = 1e9;
	int best_a, best_b;
	for (auto it : possible) {
		int cur_a = it.first.first;
		int cur_b = it.first.second;
		if (ans > cur_a + cur_b) {
			ans = cur_a + cur_b;
			best_a = cur_a;
			best_b = cur_b;
		}
	}

	//cerr << best_a << ' ' << best_b << endl;

	char symbols[] = {'W', 'D', 'L'};
	vector< pair<int, int> > path;
	while (best_a != a || best_b != b) {
		int type = possible[{best_a, best_b}].first;
		int p = possible[{best_a, best_b}].second;
		path.emplace_back(type, p);
		if (type == 0) {
			best_a /= p;
			best_b *= p * p;
		} else if (type == 1) {
			best_b /= p;
		} else {
			best_a *= p * p;
		}
	}
	reverse(path.begin(), path.end());
	cout << path.size() << endl;
	for (auto it : path) {
		cout << it.second << ' ' << symbols[it.first] << '\n';
	}

	//cerr << path.size() << endl;
	return 0;
}