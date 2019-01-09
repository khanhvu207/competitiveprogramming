#include <bits/stdc++.h>
using namespace std;

int n, D, T, a[6421], res;

inline void check()
{
	deque<int> MIN, MAX;
	int cnt = 0;
	for (int i = 0; i < D-1; i++)
	{
		while (!MIN.empty() && a[MIN.back()] >= a[i])
			MIN.pop_back();
		MIN.push_back(i);
		while (!MAX.empty() && a[MAX.back()] <= a[i])
			MAX.pop_back();
		MAX.push_back(i);
	}
	for (int i = D-1; i <= n; i++)
	{
		if (i-MIN.front()+1 > D) MIN.pop_front();
		if (i-MAX.front()+1 > D) MIN.pop_front();

		while (!MIN.empty() && a[MIN.back()] >= a[i])
			MIN.pop_back();
		MIN.push_back(i);
		while (!MAX.empty() && a[MAX.back()] <= a[i])
			MAX.pop_back();
		MAX.push_back(i);

		if (a[MAX.front()] - a[MIN.front()] <= 1) cnt++;
	}
	if (cnt == T) res++;
}

void Try(const int& i)
{
	a[i] = a[i-1] + 1;
	if (i == n) check();
	else Try(i+1);

	a[i] = a[i-1] - 1;
	if (i == n) check();
	else Try(i+1);
}

int main()
{
	freopen("SINGER.inp", "r", stdin);
	freopen("SINGER.out", "w", stdout);
	scanf("%d%d%d", &n, &D, &T);
	Try(1);
	cout << res;
}
