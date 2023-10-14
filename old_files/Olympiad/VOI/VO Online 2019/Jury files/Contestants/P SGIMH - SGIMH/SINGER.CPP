#include "bits/stdc++.h"
using namespace std;
#define maxval              0x3f3f3f3f
#define db(x)               cout << #x << " = " << (x) << endl
int n, d, t, res, cur, x[31];

void calc(int id) {
    for (int i=-2; i<=2; i++)
        if (abs(i-x[id-1]) == 1) {
            x[id] = i;
            int maxx = -2, minn = 2;
            if (id-d+1 >= 0)
                for (int j=id-d+1; j<=id; j++)
                    maxx = max(maxx, x[j]),
                    minn = min(minn, x[j]);

            if (abs(maxx-minn) <= 1)
                cur++;

            if (cur > t || t-cur > n-id) {
                if (abs(maxx-minn) <= 1)
                    cur--;
                x[id] = 0;
                continue;
            }

            if (id == n) {
/**
                for (int j=0; j<=n; j++)
                    printf("%d ", x[j]);
                printf("\n");
**/
                if (cur == t)
                    res++;
            }
            else
                calc(id+1);

            if (abs(maxx-minn) <= 1)
                cur--;

            x[id] = 0;
        }
}
int main() {
    freopen("SINGER.INP", "r", stdin); freopen("SINGER.OUT", "w", stdout);
    scanf("%d %d %d", &n, &d, &t);
    calc(1);
    printf("%d", res);
    return 0;
}
