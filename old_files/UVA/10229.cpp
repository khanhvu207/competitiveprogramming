#include <bits/stdc++.h>
using namespace std;

struct matrix {
	long long m[2][2];
	matrix() {
		m[0][0] = m[0][1] = 0;
		m[1][0] = m[1][1] = 0;
	}
};
int N, M;
long long pow2[20];

matrix matmul(matrix a, matrix b) {
	matrix ans;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j) 
			for (int k = 0; k < 2; ++k)
				ans.m[i][j] = (ans.m[i][j] % pow2[M] + (a.m[i][k] * b.m[k][j]) % pow2[M]) % pow2[M];
	return ans;
}

matrix matpow(matrix base, int p) {
	matrix ans;
	ans.m[0][0] = ans.m[1][1] = 1;
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
	pow2[0] = 1ll;
	for (int i = 1; i < 20; ++i)
		pow2[i] = pow2[i - 1] * 2ll;
	matrix base;
	base.m[0][0] = 1; base.m[0][1] = 1;
	base.m[1][0] = 1; base.m[1][1] = 0;
	while (cin >> N >> M) {
		if (N == 0) {
			cout << 0 << '\n';
			continue;
		}
		matrix res = matpow(base, N - 1);
		cout << res.m[0][0] % pow2[M] << '\n';
	}
}