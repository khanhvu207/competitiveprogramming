#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
int a[N], n, d, t, cnt = 0;

void update()
{
    int mina, maxa, tmp = 0;
    bool ok;

    for (int i = 0; i <= n - d + 1; i++)
    {
        mina = N; maxa = -N; ok = true;
        for (int j = i; j <= i + d - 1; j++)
        {
            mina = min(mina, a[j]);
            maxa = max(maxa, a[j]);
            if (maxa - mina > 1) {ok = false; break;}
        }
        if (ok) if (++tmp > t) return;
    }
    if (tmp == t) cnt++;
}

void Try(int i)
{
    for (int j = -1; j <= 1; j += 2)
    {
        a[i] = a[i - 1] + j;
        if (i < n) Try(i + 1); else update();
    }
}

int main()
{
    freopen("SINGER.INP", "r", stdin);
    freopen("SINGER.OUT", "w", stdout);

    cin >> n >> d >> t;

    a[0] = 0;
    Try(1);

    cout << cnt;

    return 0;
}
