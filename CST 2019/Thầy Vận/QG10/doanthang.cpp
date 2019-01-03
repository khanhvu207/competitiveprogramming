#include <iostream>
#include <cstdio>
using namespace std;

int n, a[33333], res = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("doanthang.inp", "r", stdin);
    freopen("doanthang.out", "w", stdout);

    cin >> n;
    for (int i = 0, l, r; i < n; ++i)
    {
        cin >> l >> r;
        ++a[l];
        --a[r];
    }
    for (int i = 1; i < 33333; ++i) a[i] += a[i - 1];

    for (int i = 1; i < 33333; ++i)
        res += (a[i] > 0);
    cout << res;
}
