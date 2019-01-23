#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 5015;

int n, m, k, s[N], c[N], cnt[30];
long long f[N], dp[N];

long long fastpow (long long a, int p)
{
	long long res = 1ll;
	while (p > 0) 
	{
		if (p & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		p >>= 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("poetry.in", "r", stdin);
	freopen("poetry.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)
		cin >> s[i] >> c[i];
	f[0] = 1ll;
	for (int i = 1; i <= k; ++i)
		for (int j = 1; j <= n; ++j)
			if (i - s[j] >= 0)
				f[i] = (f[i] + f[i - s[j]]) % mod;
	for (int e = 1; e <= n; ++e)
		for (int i = 1; i <= n; ++i)
			if (k - s[i] >= 0 && c[i] == e)
				dp[e] = (dp[e] + f[k - s[i]]) % mod;
	while (m--)
	{
		char x;
		cin >> x;
		++cnt[x - 'A'];
	}
	long long res = 1ll;
	for (char x = 'A'; x <= 'Z'; ++x)
		if (cnt[x - 'A'] > 0)
		{
			long long sum = 0ll;
			for (int e = 1; e <= n; ++e)
				sum = (sum + fastpow(dp[e], cnt[x - 'A'])) % mod;
			res = (res * sum) % mod;
		}
	cout << res;
}