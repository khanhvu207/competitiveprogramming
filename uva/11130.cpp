#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double pi = atan(1) * 4;
double a, b, v, angle, s;

int main()
{
	while (cin >> a >> b >> v >> angle >> s)
	{
		if (a == 0 && b == 0 && v == 0 && angle == 0 && s == 0) return 0;
		double l = s * v / 2.0;
		double dx = l * cos(angle / 180.0 * pi);
		double dy = l * sin(angle / 180.0 * pi);
		cout << fixed << setprecision(0) << dx / a << ' ' << dy / b << '\n';
	}
}
