#include <bits/stdc++.h>

using namespace std;

int median(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}

int n;
int a[100005], b[100005], c[100005], d[100005];
int x[200005], y[200005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        if (a[i] > c[i]) swap(a[i], c[i]);
        if (b[i] > d[i]) swap(b[i], d[i]);
        x[2 * i] = a[i];
        y[2 * i] = b[i];
        x[2 * i + 1] = c[i];
        y[2 * i + 1] = d[i];
    }
    sort(x, x + 2 * n);
    sort(y, y + 2 * n);
    int ans_x = x[n], ans_y = y[n]; //or x[n-1], y[n-1]
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (ans_x < a[i]) ans += a[i] - ans_x;
        if (ans_y < b[i]) ans += b[i] - ans_y;
        if (c[i] < ans_x) ans += ans_x - c[i];
        if (d[i] < ans_y) ans += ans_y - d[i];
    }

    cout << ans << '\n';
    cout << ans_x << ' ' << ans_y << '\n';
    for (int i = 0; i < n; ++i)
        cout << median(a[i], ans_x, c[i]) << ' ' << median(b[i], ans_y, d[i]) << '\n';
    return 0;
}
