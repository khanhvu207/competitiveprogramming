#include <bits/stdc++.h>
using namespace std;

int k, m, n, mod, P[100001], S[100001], T[100001];
bool found;

inline bool ok(const int j, const int val)
{
	for (int i = 1; i <= m; i++)
		if ((S[i]*val - P[(i-1)*n + (j-1)])%mod != 0)
			return false;
	return true;
}

void TryT(const int& i)
{
	for (int j = 0; j < mod; j++)
		if (ok(i, j))
		{
			T[i] = j;
			if (i == n) found = true;
			else TryT(i+1);
			if (found) return;
		}
}

void TryS(const int& i)
{
	for (int j = 0; j < mod; j++)
	{
		S[i] = j;
		if (i == m) TryT(1);
		else TryS(i+1);
		if (found) return;
	}
}

int main()
{
	freopen("WEDDING.inp", "r", stdin);
	freopen("WEDDING.out", "w", stdout);
	scanf("%d%d", &k, &mod);
	for (int i = 0; i < k; i++)
		scanf("%d", &P[i]);
	/*if (mod == 2)
	{
		for (m = 2; m <= sqrt(k) && !found; m++)
			if (k%m == 0)
			{
				n = k/m;
				for (int i = 0; i < n; i++)
					T[i] = -1;

				for (int i = 0; i < m && !found; i++)
					for (S[i] = 0; S[i] <= 1 && !found; S[i]++)
						for (int j = 0; j < m && !found; j++)
						{
							if (P[i*n+j] == 0)
							{
								if (S[i] == 0) continue;
								else if (T[i] == 0) continue;
								else if (T[i] == 1) break;
								else T[i] = 0;
							}
							else
							{
								if (S[i] == 0) break;
								else if (T[i] == 0) break;
								else if (T[i] == 1) continue;
								else T[i] = 1;
							}
							if (i == m && j == n) found = true;
						}
			}
		if (found)
		{
			cout << "YES\n";
			cout << m << ' ';
			for (int i = 0; i < m; i++) cout << S[i] << ' ';
			cout << "\n" << n << ' ';
			for (int i = 0; i < n; i++)
				if (T[i] > -1) cout << T[i] << ' ';
				else cout << 0 << ' ';
		}
		else cout << "NO";
	}
	else
	{*/
		for (m = 2; m <= sqrt(k); m++)
		{
			if (k%m == 0)
			{
				n = k/m;
				TryS(1);
			}
			if (found)
			{
				cout << "YES\n";
				cout << m << ' ';
				for (int i = 1; i <= m; i++) cout << S[i] << ' ';
				cout << "\n" << n << ' ';
				for (int i = 1; i <= n; i++) cout << T[i] << ' ';
				return 0;
			}
		}
		cout << "NO";
	//}
}
