#include <iostream>
using namespace std;

int n;

bool chk (int x)
{
	int m = n;
	for (int i = 0; i < x; ++i)
	{
		if ((m - 1) % x != 0) return false;
		--m;
		m -= (m / x);
	}
	return m % x == 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (cin >> n)
	{
		if (n < 0) return 0;
		bool flag = 0;
		cout << n << " coconuts, ";
		for (int i = 5; i >= 2; --i)
			if (chk(i))
			{
				cout << i << " people and 1 monkey\n", flag = 1; 
				break;
			}
		if (!flag) cout << "no solution\n";
	}
}