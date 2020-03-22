#include <bits/stdc++.h>
using namespace std;

int n, m, a[1001], b[1001], f[1001][1001];
vector<int> x, y;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				if (i == 1 || j == 1) {
					f[i][j] = 1;
				}
				else {
					f[i][j] = f[i - 2][j - 2] + 1;
				}
			}
			else {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	cout << f[n][m];
	return 0;
}
