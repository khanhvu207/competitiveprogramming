#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

inline long long gcd (long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

long long a, b, c, res=1e18, resA, resB;
map<int, int> cnt;
vector<int> d;
vector<pair<long long, long long> > f;

long long fastpow (long long base, long long expo)
{
	if (expo < 1) return 1ll;
	long long t = fastpow(base, expo / 2);
	t = t * t;
	if (expo & 1) 
		return t * base;
	else
		return t;
}

void rec (int i, long long A, long long B)
{
	if (i == (int)f.size())
	{
		if (A <= B && (B - A) < res)
		{
			res = B - A;
			resA = A;
			resB = B;
		}
		return;
	}
	rec(i + 1, A * f[i].first, B * f[i].second);
	rec(i + 1, A * f[i].second, B * f[i].first);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("gcm.inp", "r", stdin);
	freopen("gcm.out", "w", stdout);

	cin >> a >> b;
	c = gcd(a, b);

	for (int i = 2; i <= sqrt(max(a, b)); ++i)
	{	
		while (a % i == 0) {			
			if (!cnt.count(i)) d.push_back(i);
			++cnt[i];
			a /= i;
		}
		while (b % i == 0) {			
			if (!cnt.count(i)) d.push_back(i);
			++cnt[i];
			b /= i;
		}
	}
    if (a > 1) {
    	if (!cnt.count(a)) d.push_back(a);
		++cnt[a];
    }
    if (b > 1) {
    	if (!cnt.count(b)) d.push_back(b);
		++cnt[b];	
    }
    sort(d.begin(), d.end());
    
	
	for (int i = 0; i < (int)d.size(); ++i)
	{
		int k = 0;
		while (c % d[i] == 0)
			++k, c /= d[i];
		f.push_back(make_pair(fastpow(d[i], k), fastpow(d[i], cnt[d[i]] - k)));
	}
	//for (auto x : f)
	//	cout << x.first << ' ' << x.second << '\n';

	rec(0, 1ll, 1ll);
	cout << resA << ' ' << resB;
}