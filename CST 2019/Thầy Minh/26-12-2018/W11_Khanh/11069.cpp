#include <iostream>
#include <cstdio>
using namespace std;

int n;
long long f[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("11069.inp", "r", stdin);
    freopen("11069.out", "w", stdout);
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 76; ++i)
        f[i] = f[i - 2] + f[i - 3];

    while (cin >> n) {
        cout << f[n] + f[n - 1] << '\n';
    }
}
