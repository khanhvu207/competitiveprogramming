#include <bits/stdc++.h>
using namespace std;

struct matrix {
	long long m[2][2];
	matrix() {
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				m[i][j] = 0;
	}
};

long long n, mod;

matrix matmul (matrix a, matrix b) {
	matrix ans;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				ans.m[i][j] = (ans.m[i][j] % mod + ((a.m[i][k] % mod) * (b.m[k][j] % mod)) % mod) % mod;
	return ans;
}

matrix matpow (matrix base, long long p) {
	matrix ans; ///identity matrix
	ans.m[0][0] = 1ll;
	ans.m[1][1] = 1ll;
	while (p > 0) {
		if (p & 1) 
			ans = matmul(ans, base);
		base = matmul(base, base);
		p >>= 1;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int tc = 0;
	matrix base;
	base.m[0][0] = 1ll; base.m[0][1] = 1ll;
	base.m[1][0] = 1ll; base.m[1][1] = 0ll;
	while (cin >> n >> mod) {
		if (!n && !mod) return 0;
		cout << "Case " << ++tc << ": " << n << ' ' << mod << ' ';
		if (n == 0) 
			cout << 1ll % mod << '\n';
		else {
			matrix res = matpow(base, n);
			cout << (2ll * res.m[0][0] - 1ll + mod * mod) % mod << '\n';
		} 
	}
}