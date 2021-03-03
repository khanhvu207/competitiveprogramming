#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;

LL gcd(LL a, LL b)
{
	while (a > 0)
	{
		b %= a;
		swap(a,b);
	}
	return b;
}

LL fastExp(LL a, LL exp)
{
	LL res = 1;
	a = a % MOD;
	while (exp > 0)
	{
		if (exp % 2 == 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		exp /= 2;
	}
	return res;
}

int main()
{
	LL n,m,c;
	cin >> n >> m >> c;
	LL walls = fastExp(c,n*n);
	LL res = 0;
	for (int i = 0; i < m; ++i)
		res = (res + fastExp(walls, gcd(i,m))) % MOD;
	res = (res * fastExp(m, MOD-2)) % MOD;
	cout << res << endl;
}
