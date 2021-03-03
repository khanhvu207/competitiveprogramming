#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;

int n, k;
int a[300015];
double p[300015], min_p[300015];
const double eps = 1e-9;

bool chk (double x)
{
    p[1] = a[1] * 1.0;
    for (int i = 1; i <= n; i++)
        min_p[i] = 1000000000000.0;
    for (int i = 2; i <= n; i++)
        p[i] = p[i - 1] + a[i] * 1.0;
    for (int i = 1; i <= n; i++)
        p[i] = p[i] - (i * 1.0) * x;
    min_p[1] = p[1];
    for (int i = 2; i <= n; i++)
        min_p[i] = fmin(min_p[i - 1], p[i]);
    for (int i = k; i <= n; i++)
    {
        double val = p[i] - (i - k >= 1 ? min_p[i - k] : 0.0);
        if (val >= -eps) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("rate.inp", "r", stdin);
    freopen("rate.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    double l = 0.0, r = 1000000000000.0, res;
    while ((l - r) <= eps)
    {
        double m = (l + r) / 2.0;
        if (chk(m)) l = m + eps, res = m;
            else r = m - eps;
    }
    res = res * 1000000.0;
    res = round(res);
    res /= 1000000.0;
    cout << fixed << setprecision(6) << res;
    return 0;
}
