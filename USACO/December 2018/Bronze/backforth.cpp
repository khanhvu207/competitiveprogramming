#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<int> outcome;
vector<int> A, B;

void rec(int day, int sumA, int sumB, vector<int> a, vector<int> b)
{
	if (day > 6)
	{
		outcome.insert(sumA);
		return;
	}
	vector<int> ax = a;
	vector<int> bx = b;
	int tA = sumA, tB = sumB;

	if (day & 1)
	{
		for (int i = 0; i < (int)a.size(); ++i)
		{
			int x = a[i];
			b.push_back(x);
			a.erase(a.begin() + i);
			if (sumA < x) sumA = 0, x = sumA;
				else sumA -= x;
			rec(day + 1, sumA, sumB + x, a, b);
			a = ax; sumA = tA;
			b = bx; sumB = tB;
		}
	} else
	{
		for (int i = 0; i < (int)b.size(); ++i)
		{
			int x = b[i];
			a.push_back(x);
			b.erase(b.begin() + i);
			if (sumB < x) sumB = 0, x = sumB;
				else sumB -= x;
			rec(day + 1, sumA + x, sumB, a, b);
			a = ax; sumA = tA;
			b = bx; sumB = tB;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);

	for (int i = 0; i < 10; ++i)
	{
		int x; cin >> x;
		A.push_back(x);
	}
	for (int i = 0; i < 10; ++i)
	{
		int x; cin >> x;
		B.push_back(x);
	}
	rec(3, 1000, 1000, A, B);
	//for (int x : outcome)
	//	cout << x << ' '; cout << '\n';
	cout << (int)outcome.size();
}