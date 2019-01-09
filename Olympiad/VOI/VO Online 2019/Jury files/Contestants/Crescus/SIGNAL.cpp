#include <bits/stdc++.h>

using namespace std;

const int N = 50004;
const long long oo = 1e18, base = 1e7;
long long l, r, p[N], x[N], y[N], d;
int n, k;

struct rect {long long x1, y1, x2, y2;} lap[3];

rect trans(int i, long long s)
{
    s *= p[i];
    long long r = s;
    rect tmp;
    tmp.x1 = y[i] - r + x[i];
    tmp.y1 = y[i] - r - x[i];
    tmp.x2 = y[i] + r + x[i];
    tmp.y2 = y[i] + r - x[i];
    return tmp;
}

bool legal(rect a)
{
    if (a.x1 == a.x2) return a.y1 < a.y2;
    return (a.x1 < a.x2 && a.y1 <= a.y2);
}

struct rect overlap(rect a, rect b)
{
    rect tmp;
    tmp.x1 = max(a.x1, b.x1);
    tmp.y1 = max(a.y1, b.y1);
    tmp.x2 = min(a.x2, b.x2);
    tmp.y2 = min(a.y2, b.y2);
    return tmp;
}

int findPos(rect a)
{
    rect tmp;
    for (int k = 0; k <= d; k++)
    {
        tmp = overlap(lap[k], a);
        if (legal(tmp)) return k;
    }
    return -1;
}

bool intersect(long long s)
{
    d = 0;
    lap[0] = trans(0, s);
    for (int i = 1; i < n; i++)
    {
        int pos = findPos(trans(i, s));
        if (pos == -1) lap[++d] = trans(i, s);
        else lap[pos] = overlap(lap[pos], trans(i, s));
        if (d == k) return false;
    }
    return true;
}

int main()
{
    freopen("SIGNAL.INP", "r", stdin);
    freopen("SIGNAL.OUT", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> p[i], x[i] *= base, y[i] *= base;

    l = 0; r = 1e14;

    while (r - l > 1)
    {
        long long s = (l + r) / 2;
        if (intersect(s)) r = s; else l = s + 1;
    }

    cout << fixed << setprecision(7);
    if (intersect(l)) cout << (double) l / base; else cout << (double) r / base;

    //cout << endl << (double) lap.x1 / base << ' ' << (double) lap.y1 / base << ' '
    //             << (double) lap.x2 / base << ' ' << (double) lap.y2 / base;

    return 0;
}

