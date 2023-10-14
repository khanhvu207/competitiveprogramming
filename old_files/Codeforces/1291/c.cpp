#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
#ifdef kvutxdy
	freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k, res = 0;
		cin >> n >> m >> k;
		vector<int> A(n + 1);
		k = min(k, m - 1);
		for (int i = 1; i <= n; ++i) cin >> A[i];
		for (int i = 1; i <= k + 1; ++i) {
			int t = numeric_limits<int>::max();
			for (int j = 0; j <= m - k - 1; ++j)
				t = min(t, max(A[i + j], A[i + j + n - m]));
			res = max(res, t);
		}
		cout << res << '\n';
	}
}