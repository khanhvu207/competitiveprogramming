#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

struct rect {int x1, x2, y1, y2;} a[N], b[N];

bool cmpx(rect a, rect b) {return a.x1 < b.x1;}
bool cmpy(rect a, rect b) {return a.y1 < b.y1;}

int n, X, Y;
long long sum = 0;

int dist(int X, int Y, rect a) {return abs(X - a.x1) + abs(Y - a.y1);}

int main()
{
    freopen("TIGERSUGAR.INP", "r", stdin);
    freopen("TIGERSUGAR.OUT", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    for (int i = 0; i < n; i++) b[i] = a[i];

    sort(a, a + n, cmpx); X = a[n / 2].x1;
    sort(a, a + n, cmpy); Y = a[n / 2].y1;

    for (int i = 0; i < n; i++) sum += dist(X, Y, b[i]);

    cout << sum << '\n' << X << ' ' << Y << '\n';
    for (int i = 0; i < n; i++) cout << b[i].x1  << ' ' << b[i].y1 << '\n';

    return 0;
}
