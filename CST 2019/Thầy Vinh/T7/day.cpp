#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n;
long long a[300015], b[300015], c[300015];

long long calc (long long m)
{
    c[n >> 1] = m;
    for (int l = (n >> 1) - 1; l >= 0; --l) c[l] = c[l + 1] + 1;
    for (int r = (n >> 1) + 1; r < n; ++r) c[r] = c[r - 1] + 1;

    long long cost = 0;
    for (int i = 0; i < n; ++i)
        cost += abs(c[i] - a[i]) + abs(c[i] - b[i]);
    return cost;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("day.inp", "r", stdin);
    freopen("day.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long l = -1e12 - 5000, r = 1e12 + 5000;

    while (l <= r)
    {
        long long mid = (l + r) >> 1ll;
        if (calc(mid - 1ll) > calc(mid + 1ll)) l = mid + 1ll;
            else r = mid - 1ll;
    }
    cout << calc(l);
}
