#include "bits/stdc++.h"
using namespace std;
#define MOD             998244353
int n, c, curx, cury, maxx, maxy;
struct S {
    int x1, y1, x2, y2;
}sch[200001];
struct data {
    int x, y;
}qts[200001];
map<int, int> x, y;
long long dist;
int main() {
    freopen("TIGERSUGAR.INP", "r", stdin); freopen("TIGERSUGAR.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        scanf("%d %d %d %d", &sch[i].x1, &sch[i].y1, &sch[i].x2, &sch[i].y2);
        x[sch[i].x1]++, y[sch[i].y1]++, x[sch[i].x2]++, y[sch[i].y2]++;
/**
        if (sch[i].x1 == sch[i].x2)
            x[sch[i].x1]--;
        if (sch[i].y1 == sch[i].y2)
            x[sch[i].y1]--;
**/
        if (x[sch[i].x1] > maxx) {
            curx = sch[i].x1;
            maxx = x[sch[i].x1];
        }
        if (x[sch[i].x2] > maxx) {
            curx = sch[i].x2;
            maxx = x[sch[i].x2];
        }
        if (y[sch[i].y1] > maxy) {
            cury = sch[i].y1;
            maxy = y[sch[i].y1];
        }
        if (y[sch[i].y2] > maxy) {
            cury = sch[i].y2;
            maxy = y[sch[i].y2];
        }
    }

    qts[c++] = {curx, cury};



    printf("%d\n", dist);
    for (int i=0; i<c; i++)
        printf("%d %d\n", qts[i].x, qts[i].y);

    return 0;
}
