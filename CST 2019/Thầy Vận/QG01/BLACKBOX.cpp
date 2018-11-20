#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, cnt = 0;
int a[30005], b[30005] = {0};
int BIT[30005] = {0};

void update (int x)
{
    for (; x <= 30001; x += x & (-x))
        BIT[x]++;
}

int get (int x)
{
    int res = 0;
    for (; x >= 1; x -= x & (-x))
        res += BIT[x];
    return res;
}

int query (int k)
{
    int l = 1, r = 30000, res;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (get(m - 1) >= k) r = m - 1, res = r;
            else l = m + 1;
    }
    return res - 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("BLACKBOX.INP", "r", stdin);
    freopen("BLACKBOX.OUT", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0, x; i < m; i++)
        cin >> x, b[x]++;
    vector<int> c;
    for (int i = 0; i < n; i++)
        c.push_back(a[i]);
    sort(c.begin(), c.end());
    for (int i = 1; i <= n; i++)
    {
        int x = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
        update(x);
        while (b[i] > 0)
        {
            cout << c[query(++cnt)] << '\n';
            b[i]--;
        }
    }
    return 0;
}
