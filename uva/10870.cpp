#include <bits/stdc++.h>
using namespace std;

struct matrix {
	long long m[15][15];
	matrix() {
		for (int i = 0; i < 15; ++i)
			for (int j = 0; j < 15; ++j)
				m[i][j] = 0ll;
	}
};

long long d, n, mod, f[15];

matrix matmul (matrix a, matrix b) {
	matrix ans;
	for (int i = 0; i < d; ++i)
		for (int j = 0; j < d; ++j)
			for (int k = 0; k < d; ++k)
				ans.m[i][j] = (ans.m[i][j] % mod + ((a.m[i][k] % mod) * (b.m[k][j] % mod)) % mod) % mod;
	return ans;
}

matrix matpow (matrix base, long long p) {
	matrix ans;
	for (int i = 0; i < d; ++i)
		ans.m[i][i] = 1ll;
	while (p) {
		if (p & 1ll)
			ans = matmul(ans, base);
		base = matmul(base, base);
		p >>= 1ll;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	while (cin >> d >> n >> mod) {
		if (!d && !n && !mod) return 0;
		matrix base;
		for (int i = 0; i < d; ++i)
			cin >> base.m[0][i];
		for (int i = 1; i < d; ++i)
			base.m[i][i - 1] = 1;
		for (int i = 0; i < d; ++i)
			cin >> f[i];
		if (n <= d) {
			cout << f[n - 1] << '\n';
			continue;
		}
		matrix ans = matpow(base, n - d);
		long long res = 0;
		for (int i = 0; i < d; ++i)
			res = (res + (f[d - i - 1] * ans.m[0][i]) % mod) % mod;
		cout << res << '\n';
	}
}

