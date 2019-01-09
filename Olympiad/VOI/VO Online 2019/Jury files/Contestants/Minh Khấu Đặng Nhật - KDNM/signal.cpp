#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

const double eps = 1e-9;

int n, k, x[50000], y[50000], s[50000];
double res;

bool solve(double m) {
    double x1 = -5e7, x2 = 5e7;
    double y1 = -5e7, y2 = 5e7;
    for (int i = 0; i < n; ++i)
        x1 = max(x1, x[i] + y[i] - s[i] * m), y1 = max(y1, x[i] - y[i] - s[i] * m),
        x2 = min(x2, x[i] + y[i] + s[i] * m), y2 = min(y2, x[i] - y[i] + s[i] * m);
    return x1 - x2 < eps && y1 - y2 < eps;
}

int main() {
    freopen("signal.inp", "r", stdin);
    freopen("signal.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> s[i];
    for (double l = 1e-7, r = 2e7; l - r < eps;) {
        double m = (l + r) / 2.0;
        if (solve(m))
            res = m, r = m - 1e-7;
        else l = m + 1e-7;
    }
    cout << fixed << setprecision(7) << res;
}
