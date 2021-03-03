#include <iostream>
#include <cstdio>
using namespace std;

int n, k;

int main()
{
	while (cin >> n >> k)
	{
		int res = n;
		while (n >= k)
		{
			res += n / k;
			n = n / k + n % k;
		}
		cout << res << '\n';
	}
}