#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double pi = acos(-1.0);

double a, b, t, m, n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (cin >> a >> b >> t >> m >> n)
    {
        if (a == 0 && b == 0 && t == 0 && m == 0 && n == 0) return 0;
        double angle = atan((n * b) / (m * a));
        double v = (m * a) / (cos(angle) * t);

        angle = angle * 180.0 / pi;
        cout << fixed << setprecision(2) << angle << ' ' << v << '\n';
    }
}