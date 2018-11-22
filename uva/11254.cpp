#include <iostream>
#include <cmath>
using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (cin >> n)
	{
		if (n < 0) return 0;
		cout << n << " = ";
		for (int i = sqrt(2 * n); i >= 1; --i)
			if (2 * n % i == 0)
			{
				int a = i;
				int b = 2 * n / i;
				if (a > b) swap(a, b);
				if ((b - a + 1) % 2 == 0)
				{
					cout << (b - a + 1) / 2 << " + ... + " << (b - a + 1) / 2 + a - 1 << '\n';
					break;
				}
			}
	}
}