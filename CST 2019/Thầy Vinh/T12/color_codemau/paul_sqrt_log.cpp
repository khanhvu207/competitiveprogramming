#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* 
 * For given n, m and c, the answer is
 * 
 *       1/m * sum_d (x^(m/d) * phi(d))
 * 
 * where x = c^(n*n), phi is Euler's totient function,
 * and d ranges over the divisors of m.
 * 
 * This can be evaluated in O(sqrt(m)*log(m) + log(n)).
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

vector<pair<ll,ll>> fac;
	
void factorize(ll n) {
	for (ll d = 2; d*d <= n; d++) {
		if (n % d) continue;
		ll cnt = 0;
		while (n % d == 0) n /= d, cnt++;
		fac.emplace_back(d,cnt);
	}
	if (n > 1) fac.emplace_back(n,1);
}

ll rec(ll m, ll x, ll i, ll d, ll phi) {
	if (i == fac.size()) return power(x,m/d) * phi % MOD;
	
	ll p, cnt;
	tie(p,cnt) = fac[i];

	ll res = 0;
	for (int j = 0; j <= cnt; j++) {
		res = (res + rec(m,x,i+1,d,phi)) % MOD;
		d *= p;
		phi *= j == 0 ? p-1 : p;
	}
	return res;
}

int main() {
	ll n, m, c;
	cin >> n >> m >> c;
	c = power(c,n*n);

	factorize(m);
	cout << rec(m,c,0,1,1) * power(m,MOD-2) % MOD << endl;
}
