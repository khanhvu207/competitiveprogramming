#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* 
 * For given n, m and c, the answer is
 * 
 *       1/m * sum_k x^gcd(m,k)
 * 
 * where x = c^(n*n), and 0 <= k < m.
 * 
 * This can be evaluated in O(m*log(m) + log(n)).
 */

const ll MOD = 1e9+7;

ll power(ll a, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1) res = res*a % MOD;
		a = a*a % MOD;
		n /= 2;
	}
	return res;
}

int main() {
	ll n, m, c;
	cin >> n >> m >> c;
	c = power(c,n*n);

	ll sum = 0;
	for (ll k = 0; k < m; k++) {
		sum = (sum + power(c,__gcd(m,k))) % MOD;
	}
	cout << sum * power(m,MOD-2) % MOD << endl;
}
