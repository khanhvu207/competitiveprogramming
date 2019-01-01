#include <iostream>
#include <cstdio>
using namespace std;

int n;
long long f[35], g[35];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("10918.inp", "r", stdin);
    freopen("10918.out", "w", stdout);

    f[0] = 1;
    f[1] = 0;
    f[2] = 3;
    g[2] = 2;
    for (int i = 3; i <= 30; ++i) {
        f[i] = f[i - 2] * 3 + g[i - 2];
        g[i] = g[i - 2] + f[i - 2] * 2;
    }
    while (cin >> n) {
        if (n == -1) return 0;
        cout << f[n] << '\n';
    }
}
