#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    freopen("wedding.inp", "r", stdin);
    freopen("wedding.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    cout << "YES\n1 1\n" << n;
    for (int i = 0, x; i < n; ++i)
        cin >> x, cout << ' ' << x;
}
