#include <iostream>
#include <algorithm>
using namespace std;

int t, n, a[15], C;

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		nth_element(a, a + (n / 2), a + n);
		cout << "Case " << ++C << ": " << a[n / 2] << '\n';
	}
}