#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

ll x0, y0, ax, ay, bx, by, xs, ys, t;
ll x[60], y[60], dist[60];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> x[1] >> y[1] >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    int lim = 59;
    for (int i = 2; i <= 59; ++i) {
        x[i] = x[i - 1] * ax + bx;
        y[i] = y[i - 1] * ay + by;
        dist[i] = dist[i - 1] + x[i] - x[i - 1] + y[i] - y[i - 1];
        if (dist[i] > 1e16) {
            lim = i;
            break;
        }
    }
    int ans = 0;
    for (int a = 1; a <= lim; ++a) {
        for (int b = a; b >= 1; --b) {
            for (int c = a; c <= lim; ++c) {
                ll total = abs(xs - x[a]) + abs(ys - y[a]);
                if (total <= t) ans = max(ans, 1);
                else continue;
                total += dist[a] - dist[b];
                if (total <= t) ans = max(ans, a - b + 1);
                else continue;
                total += dist[c] - dist[b];
                if (total <= t) ans = max(ans, c - b + 1);
            }
        }
    }
    cout << ans;
}
