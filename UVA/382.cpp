#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int n;

string convert (int x)
{
	string t="";
	while (x) t = (char)(x % 10 + 48) + t, x /= 10;
	while ((int)t.size() < 5) t = ' ' + t;
	return t; 
}

int main()
{
	cout << "PERFECTION OUTPUT\n";
	while (cin >> n)
	{
		if (n < 1) break;
		cout << convert(n) << ' ';
		int sum = 0;
		for (int i = 1; i <= n / 2; ++i)
			if (n % i == 0) sum += i;
		if (sum < n) cout << " DEFICIENT\n";
			else if (sum > n) cout << " ABUNDANT\n";
				else cout << " PERFECT\n";
	}
	cout << "END OF OUTPUT\n";
}