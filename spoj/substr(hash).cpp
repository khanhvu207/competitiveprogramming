#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1000015;

string t, p;
long long hasht[N], hashp, powx[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> t >> p;
	powx[0] = 1ll;
	for (int i = 1; i <= 1000000; ++i)
		powx[i] = (powx[i - 1] * 31ll) % mod;
	for (int i = 1; i <= (int)t.size(); ++i) 
		hasht[i] = ((t[i - 1] * powx[i - 1]) % mod + hasht[i - 1]) % mod;
	for (int i = 1; i <= (int)p.size(); ++i)
		hashp = ((p[i - 1] * powx[i - 1]) % mod + hashp) % mod;
	for (int i = 1; i <= (int)t.size() - (int)p.size() + 1; ++i) {
		long long subt = (hasht[i + (int)p.size() - 1] - hasht[i - 1] + mod * 5ll) % mod;
		long long tmp = (hashp * powx[i - 1]) % mod;
		if (subt == tmp)
			cout << i << ' ';
	}
}