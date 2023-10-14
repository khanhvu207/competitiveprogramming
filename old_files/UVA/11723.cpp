#include <iostream>
#include <cmath>
using namespace std;

int n, k, C;

int main()
{
	while (cin >> n >> k)
	{
		if (n < 1 && k < 1) return 0;
		int x = ceil((double)(n - k) / k);
		cout << "Case " << ++C << ": ";
		if (n < k) cout << 0;
		else if (x > 26) cout << "impossible";
		else cout << x;
		cout << '\n';
	}
}