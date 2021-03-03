#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int t, C = 0;
double d, v, u;

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> d >> v >> u;
		if (v >= u || v == 0 || u == 0)
		{
			cout << "Case " << ++C << ": can't determine\n";
			continue;
		}
		double a = d / u;
		double b = d / sqrt(u * u - v * v);
		cout << "Case " << ++C << ": ";
		cout << fixed << setprecision(3) << fabs(a - b) << '\n';
	}
}