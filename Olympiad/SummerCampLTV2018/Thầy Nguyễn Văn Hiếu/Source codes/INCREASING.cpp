#include <bits/stdc++.h>

using namespace std;

long long n, h, a[200005], f[200005], s[200005], st[4 * 200005];
long long maxs = 0, res = 0;

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        st[v] = f[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    st[v] = max(st[v * 2], st[v * 2 + 1]);
}

long long get(int v, int tl, int tr, int l, int r)
{
    if (tr < l || tl > r) return -1e6;
    if (l <= tl && tr <= r) return st[v];
    int tm = (tl + tr) / 2;
    return max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
}

int main()
{
    freopen("INCREASING.INP", "r", stdin);
    freopen("INCREASING.OUT", "w", stdout);


    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) f[i] = a[i] - i;
    build(1, 1, n);
    s[0] = 0;
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    bool flag = false;
    for (int i = 1; i <= n - h + 1; i++) if (get(1, 1, n, i, i + h - 1) <= 1 - i)
        maxs = max(maxs, s[i + h - 1] - s[i - 1]), flag = true;
    res = (h * (h + 1) / 2) - maxs;
    if (!flag) res = -1;
    cout << res;
    return 0;
}

