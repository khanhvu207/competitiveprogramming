#include <bits/stdc++.h>
using namespace std;

int t, r, n;
int a[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> r;
	cin >> t;
	while (t--) {
		int res = 0;
		cin >> n;
		for (int i = 0; i < 3; ++i) {
			int x;
			cin >> x;
			if (r == 1)
				res += n - x;
			else
				res = max(res, n - x);
		}
		res = max(0, n - res);
		cout << res << '\n';
	}
}