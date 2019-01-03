#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int N = 215;
const int inf = 1e9;

int n, r, d[N], a[N], b[N], f[N][1015];
vector<int> resa, resb;

int dp(int i, int R) {
    if (f[i][R] != -1)
        return f[i][R];
    if (i == n)
        return 0;
    f[i][R] = inf;
    for (int k = 0; k <= d[i]; ++k)
        if (k <= R)
            f[i][R] = min(f[i][R], k * a[i] + (d[i] - k) * b[i] + dp(i + 1, R - k));
    return f[i][R];
}

void trace(int i, int R) {
    if (i == n)
        return;
    int tmp = inf;
    int p;
    for (int k = 0; k <= d[i]; ++k)
        if (k <= R) {
            int cost = k * a[i] + (d[i] - k) * b[i] + dp(i + 1, R - k);
            if (cost < tmp) {
                tmp = cost;
                p = k;
            }
        }
    resa.push_back(p);
    resb.push_back(d[i] - p);
    trace(i + 1, R - p);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("haikho.inp", "r", stdin);
    freopen("haikho.out", "w", stdout);
    cin >> n >> r;
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    memset(f, -1, sizeof f);
    cout << dp(0, r) << '\n';
    trace(0, r);
    for (int i = 0; i < (int)resa.size(); ++i)
        cout << resa[i] << ' ';
    cout << '\n';
    for (int i = 0; i < (int)resb.size(); ++i)
        cout << resb[i] << ' ';
}
