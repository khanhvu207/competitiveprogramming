#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int t, n, m, bit[200015], last[100015];

void update (int x, int v)
{
    for (; x <= 200001; x = x | (x + 1))
        bit[x] += v;
}

int get (int x)
{
    int cnt = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
        cnt += bit[x];
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("bstp.inp", "r", stdin);
    freopen("bstp.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(bit, 0, sizeof bit);
        for (int i = 1; i <= n; i++)
            update(i + m, 1), last[i] = i + m;
        int f = 1 + m;
        for (int i = 0, x; i < m; i++)
        {
            cin >> x;
            cout << get(last[x] - 1) << ' ';
            update(last[x], -1);
            last[x] = --f;
            update(last[x], 1);
        }
        cout << '\n';
    }
    return 0;
}
