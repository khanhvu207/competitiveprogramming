#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1;
int l, r, res[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 2; i < MAXN; ++i) {
		int x = i, cnt = 0;
		for (int j = 2; j * j <= x; ++j) {
			if (x % j == 0) {
				cnt += j;
				if (x / j != j) {
					cnt += x / j;
				}
			}
		}
		res[i] = ++cnt > i;
	}
	for (int i = 2; i < MAXN; ++i) {
		res[i] += res[i - 1];
	}
	cin >> l >> r;
	cout << res[r] - (!l ? 0 : res[l - 1]);
	return 0;
}
