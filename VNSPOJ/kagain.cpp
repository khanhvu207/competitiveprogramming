#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<long long> a(n), prefix(n), suffix(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		deque<int> q;
		for (int i = 0; i < n; ++i) {
			while (!q.empty() && a[q.back()] >= a[i])
				q.pop_back();
			prefix[i] = (q.empty() ? -1 : q.back()) + 1;
			q.push_back(i);
		}
		q.clear();
		for (int i = n - 1; i >= 0; --i) {
			while (!q.empty() && a[q.back()] >= a[i])
				q.pop_back();
			suffix[i] = (q.empty() ? n : q.back()) - 1;
			q.push_back(i);
		}
		long long res = 0ll;
		int left = 0, right = 0;
		for (int i = 0; i < n; ++i) 
			if ((suffix[i] - prefix[i] + 1ll) * a[i] > res) {
				res = (suffix[i] - prefix[i] + 1ll) * a[i] * 1ll;
				left = prefix[i];
				right = suffix[i];
			}
		cout << res << ' ' << left + 1 << ' ' << right + 1 << '\n';
	}
}