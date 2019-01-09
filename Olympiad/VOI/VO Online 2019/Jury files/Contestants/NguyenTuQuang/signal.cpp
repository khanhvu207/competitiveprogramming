#include <bits/stdc++.h>

using namespace std;

const double scale = sqrt(2);

const int N = 5e4 + 10;
const double EPS = 1e-7;

int n, k;
vector<double> a[N];
int w[N];

bool check(double rat) {
    if (k == 1) {
        for(int j = 0; j <= 1; j++) {
            double L = -1e16, R = 1e16;
            for(int i = 1; i <= n; i++) {
                L = max(L, a[i][j] - rat * w[i]);
                R = min(R, a[i][j] + rat * w[i]);
            }
            if (L >= R) return 0;
        }
        return 1;
    }
}
int main() {
    freopen("signal.inp", "r", stdin);
    freopen("signal.out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y >> w[i];
        a[i] = {(x - y) / scale, (x + y) / scale};
    }
    double L = 0, R = 3e7;
    while (L < R - EPS) {
        double mid = (L + R) / 2;
        if (check(mid)) R = mid;
        else L = mid;
    }
    cout << fixed << setprecision(9) << R * scale;
}
