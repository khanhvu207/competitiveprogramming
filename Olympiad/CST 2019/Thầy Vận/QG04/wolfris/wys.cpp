#include <iostream>
#include <stdio.h>

using namespace std;

int n, a[100015], res;

int main() {
    freopen("wys.inp", "r", stdin);
    freopen("wys.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], a[i] += a[i - 1];
    for (int i = 1, j = 1; i <= n; ++i) {
        for (; a[i] - a[j] > a[n] - a[i] + a[j]; ++j);
        res = max(res, a[i] - a[j]);
    }
    cout << res;
}
