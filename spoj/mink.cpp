#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) 
			cin >> a[i];
		deque<int> q;
		for (int i = 0; i < k; ++i) {
			while (!q.empty() && a[q.back()] > a[i])
				q.pop_back();
			q.push_back(i);
		}
		cout << a[q.front()] << ' ';
		for (int l = 1, r = k; r < n; ++l, ++r) {
			while (q.front() < l)
				q.pop_front();
			while (!q.empty() && a[q.back()] > a[r])
				q.pop_back();
			q.push_back(r);
			cout << a[q.front()] << ' ';
		}
		cout << '\n';
	}
}