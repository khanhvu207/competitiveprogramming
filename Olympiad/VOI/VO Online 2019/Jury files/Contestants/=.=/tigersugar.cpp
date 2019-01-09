#include <iostream>
#include <stdio.h>

using namespace std;

int n, x1[100000], y1[100000], x2[100000], y2[100000], X, Y;

int calc(int x, int a[], int b[]) {
    int res = 0;
    for (int i = 0; i < n; ++i)
        if (a[i] >= x) res += a[i] - x;
        else if (b[i] <= x) res += x - b[i];
    return res;
}

int solve(int a[], int b[]) {
    for (int l = 0, r = 1e9, m; l <= r;) {
        if (l == r) return l;
        m = l + r >> 1;
        if (calc(m, a, b) < calc(m + 1, a, b)) r = m;
        else if (calc(m, a, b) > calc(m + 1, a, b)) l = m + 1;
        else return m;
    }
}

int main() {
    freopen("tigersugar.inp", "r", stdin);
    freopen("tigersugar.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        if (x1[i] > x2[i]) swap(x1[i], x2[i]);
        if (y1[i] > y2[i]) swap(y1[i], y2[i]);
    }
    X = solve(x1, x2); Y = solve(y1, y2);
    cout << calc(X, x1, x2) + calc(Y, y1, y2) << '\n' << X << ' ' << Y << '\n';
    for (int i = 0; i < n; ++i) {
        if (x1[i] >= X) cout << x1[i];
        else if (x2[i] <= X) cout << x2[i];
        else cout << X;
        cout << ' ';
        if (y1[i] >= Y) cout << y1[i];
        else if (y2[i] <= Y) cout << y2[i];
        else cout << Y;
        cout << '\n';
    }
}
