#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>

using namespace std;

int n;
double k, x[100015], t[100015];

int main() {
    freopen("baotin.inp", "r", stdin);
    freopen("baotin.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> k >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    sort(x + 1, x + n + 1);
    for (int i = 1; i <= n; ++i)
        if (x[i] - t[i - 1] <= x[i - 1] + k) {
            t[i] = t[i - 1];
            if (x[i] >= x[i - 1] + k) x[i] = x[i - 1] + k;
            else x[i] += min(t[i], x[i - 1] + k - x[i]);
        }
        else {
            double tmp = (x[i] - t[i - 1] - x[i - 1] - k) / 2;
            t[i] = t[i - 1] + tmp; x[i] -= tmp;
        }
    cout << fixed << setprecision(3) << t[n];
}
