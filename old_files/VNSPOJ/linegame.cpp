#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll a[1000001], f[1000001][2];

ll dp(int cur, bool minus) {
	ll& res = f[cur][minus];
	if (res != -1) {
		return res;
	}
	if (cur == n) {
		res = 0;
		return res;
	}
	res = dp(cur + 1, minus);
	res = max(res, dp(cur + 1, minus ^ 1) + (minus ? -1ll * a[cur] : a[cur]));
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	memset(f, -1, sizeof f);
	cout << dp(0, 0);
	return 0;
}
