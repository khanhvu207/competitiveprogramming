#include <bits/stdc++.h>
using namespace std;
const int N = 1015;

int n, m;
bool a[N][N];

int maxsquare(bool flag) {
	int res = 0;
	vector<int> h(m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			h[j] = (a[i][j] == flag ? h[j] + 1 : 0);
		deque<int> q;
		vector<int> prefix(m), suffix(m);
		for (int j = 0; j < m; ++j) {
			while (!q.empty() && h[q.back()] >= h[j])
				q.pop_back();
			prefix[j] = (q.empty() ? -1 : q.back()) + 1;
			q.push_back(j);
		}
		q.clear();
		for (int j = m - 1; j >= 0; --j) {
			while (!q.empty() && h[q.back()] >= h[j])
				q.pop_back();
			suffix[j] = (q.empty() ? m : q.back()) - 1;
			q.push_back(j);
		}
		for (int j = 0; j < m; ++j)
			if (h[j] != 0)
				res = max(res, min(h[j], suffix[j] - prefix[j] + 1));
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	cout << max(maxsquare(0), maxsquare(1));
}