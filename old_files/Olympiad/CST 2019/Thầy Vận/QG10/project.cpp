#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
long long h, s, d, f, a[100015];
int sparse[20][100015], w[100015], res[100015];

int getmax (int l, int r)
{
    int x = floor(log2(r - l + 1));
    return max(sparse[x][l], sparse[x][r - (1 << x) + 1]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("project.inp", "r", stdin);
    freopen("project.out", "w", stdout);

    cin >> n;
    cin >> h >> s >> d;
    f = floor((double)(h + d) / s);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sparse[0][i] = a[i];
    }

    for (int x = 1; (1 << x) <= n; ++x)
        for (int i = 1; i + (1 << x) - 1 <= n; ++i)
            sparse[x][i] = max(sparse[x - 1][i], sparse[x - 1][i + (1 << (x - 1))]);

    long long cost = h * a[1] + s * a[1];
    res[1] = a[1];
    int cur = res[1];

    for (int i = 2; i <= n; ++i)
    {
        int t = getmax(i, min(i + f, n * 1ll));
        if (t < cur) {
            cost += (cur - t) * d;
            cur = t;
        }
        if (cur < a[i]) {
            cost += (a[i] - cur) * h;
            cur = a[i];
        }
        cost += s * cur;
        res[i] = cur;
    }
    cost += d * cur;
    cout << cost << '\n';
    for (int i = 1; i <= n; ++i)
        cout << res[i] << ' ';
}
