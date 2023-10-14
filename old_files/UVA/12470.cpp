#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 9;
struct matrix {
	long long m[3][3];
	matrix() {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				m[i][j] = 0;
	}
};
long long n;

matrix matmul(matrix a, matrix b) {
	matrix ans;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
				ans.m[i][j] = (ans.m[i][j] + (a.m[i][k] * b.m[k][j]) % mod) % mod;
	return ans;
}

matrix matpow(matrix base, long long p) {
	matrix ans;
	ans.m[0][0] = ans.m[1][1] = ans.m[2][2] = 1;
	while (p) {
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
	matrix base;
	base.m[0][0] = base.m[0][1] = base.m[0][2] = 1;
	base.m[1][0] = base.m[2][1] = 1;
	while (cin >> n) {
		if (n < 1) return 0;
		if (n <= 3) 
			cout << n - 1 << '\n';
		else {
			matrix ans = matpow(base, n - 3);
			long long res = (2ll * ans.m[0][0]) % mod + (1ll * ans.m[0][1]) % mod;
			cout << res % mod << '\n';
		}
	}
}