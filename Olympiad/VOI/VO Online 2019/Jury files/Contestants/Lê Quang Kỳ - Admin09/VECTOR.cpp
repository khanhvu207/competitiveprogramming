#include <bits/stdc++.h>
using namespace std;

int n, m, Q, prePrime[10000001], id[10000001];
vector<int> Prime;
vector<pair<char, int> > res;

void Eratos()
{
	for (int i = 2; i <= 3162; i++)
		if (prePrime[i] == 0)
		{
			for (int j = i*i; j <= 10000000; j += i)
				prePrime[j] = i;
		}
	for (int i = 2; i <= 10000000; i++)
		if (prePrime[i] == 0)
		{
			Prime.push_back(i);
			id[i] = Prime.size()-1;
			prePrime[i] = i;
		}
}

inline void Phantich(int x, vector<int>& Fact)
{
	while (x > 1)
	{
		int p = prePrime[x];
		Fact[id[p]]++;
		x /= p;
	}
}

int main()
{
	cin.tie(nullptr);
	freopen("VECTOR.inp", "r", stdin);
	freopen("VECTOR.out", "w", stdout);
	Eratos();
	scanf("%d", &m);
	vector<int> Thang(Prime.size(), 0);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &Q);
		Phantich(Q, Thang);
	}
	scanf("%d", &n);
	vector<int> Duc(Prime.size(), 0);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &Q);
		Phantich(Q, Duc);
	}

	for (int i = 0; i < Prime.size(); i++)
	{
		if (Duc[i] > 0)
		{
			if (Duc[i]%2 == 1)
			{
				Duc[i]++;
				res.push_back({'D', Prime[i]});
			}
			while (Duc[i] > 0)
			{
				Duc[i] -= 2;
				Thang[i]++;
				res.push_back({'W', Prime[i]});
			}
		}
		if (Thang[i] > 0)
		{
			if (Thang[i]%2 == 1)
			{
				res.push_back({'D', Prime[i]});
				res.push_back({'D', Prime[i]});
				res.push_back({'W', Prime[i]});
				Thang[i]++;
			}
			while (Thang[i] > 0)
			{
				Thang[i] -= 2;
				res.push_back({'L', Prime[i]});
			}
		}
	}
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); i++)
		cout << res[i].second << ' ' << res[i].first << "\n";
}
