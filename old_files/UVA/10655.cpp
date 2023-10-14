#include <bits/stdc++.h>
using namespace std;

struct matrix {
	long long m[2][2];
	matrix() {
		m[0][0] = 0; m[0][1] = 0;
		m[1][0] = 0; m[1][1] = 0;
	}
};

long long p, q, n;

matrix matmul (matrix a, matrix b) {
	matrix ans;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				ans.m[i][j] += a.m[i][k] * b.m[k][j];
	return ans;
}

matrix matpow (matrix base, long long p) {
	matrix ans;
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
	while (cin >> p >> q >> n) {
		if (n == 0)
			cout << 2 << '\n';
		else if (n == 1)
			cout << p << '\n';
		else {
			matrix base;
			base.m[0][0] = p;
			base.m[0][1] = -q;
			base.m[1][0] = 1;
			base.m[1][1] = 0;
			matrix ans = matpow(base, n - 1);
			long long res = p * ans.m[0][0] + 2 * ans.m[0][1];
			cout << res << '\n';
		} 
	}
}