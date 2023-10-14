#include <bits/stdc++.h>

using namespace std;

long long n, k, a[100005], mn = 1e9, mx = 0, b[1000005], minb[1000005], prefix[100005];

bool chk(int P)
{
    for (int i = 1; i <= n; i++) b[i] = a[i] - P;
    minb[0] = 1e18; b[0] = 0;
    for (int i = 1; i <= n; i++) b[i] += b[i - 1], minb[i] = min(minb[i - 1], b[i]);
    int L = 1;
    for (int R = 1; R <= n; R++)
    {
        while (prefix[R] - prefix[L - 1] >= k) L++;
        if (minb[L - 1] <= b[R]) return true;
    }
    return false;
}

int main()
{
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], mn = min(mn, a[i]), mx = max(mx, a[i]);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + a[i];
    int l = mn, r = mx, k;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (chk(m)) l = m + 1, k = m; else r = m - 1;
    }
    cout << k;
    //for (int i = mn; i <= mx; i++) cout << chk(i) << '\n';

    return 0;
}
