#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n, m, tmp, dpt; 
int a[100015], lua[100015], b[100015], t[100015];

bool chk (int top, int gt)
{
    if (lua[a[m] - gt] == 0) return false;
    for (int i = 1; i <= top; ++i)
        if (lua[gt - b[t[i]]] == 0) return false;
    return true;
}

void update (int top, int gt)
{
    --lua[a[m] - gt];
    for (int i = 1; i <= top; ++i)
        --lua[gt - b[t[i]]];
}

void update2 (int top, int gt)
{
    ++lua[a[m] - gt];
    for (int i = 1; i <= top; ++i)
        ++lua[gt - b[t[i]]];
}

void rec (int x)
{
    if (x == n - 1)
    {
        for (int i = 1; i <= x; ++i)
            cout << b[t[i]] << ' ';
            cout << a[m];
            exit(0);
    }
    for (int i = t[x]; i <= tmp; ++i)
        if (chk(x, b[i]))
        {
            dpt += 2 * x;
            update(x, b[i]);
            t[x + 1] = i;
            rec(x + 1);
            update2(x, b[i]);
        }
}

int main()
{
    freopen("ppoint.inp", "r", stdin);
    freopen("ppoint.out", "w", stdout);

    cin >> n;
    m = n * (n - 1) / 2;
    for (int i = 1; i <= m; ++i) cin >> a[i];
    sort(a + 1, a + m + 1);

    for (int i = 1; i <= m; ++i) lua[a[i]]++;

    tmp = 0;
    for (int i = 1; i <= m; ++i)
        if (a[i - 1] < a[i] && lua[a[m] - a[i]] > 0)
        {
            ++tmp;
            b[tmp] = a[i];
        }
    rec(0);
    cout << -1;
}