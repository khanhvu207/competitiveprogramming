#include "bits/stdc++.h"
using namespace std;
int n, m, a[321], b[321];
int main() {
    freopen("VECTOR.INP", "r", stdin); freopen("VECTOR.OUT", "w", stdout);
    scanf("%d", &m);
    for (int i=1; i<=m; i++)
        scanf("%d", &a[i]);

    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d", &b[i]);

    printf("%d\n", 4*m+6*n);
    {
        for (int i=1; i<=n; i++)
            printf("%d D\n", b[i]);


        for (int i=1; i<=n; i++)
            printf("%d W\n", b[i]);


        for (int i=1; i<=m; i++) {
            printf("%d D\n", a[i]);
            printf("%d D\n", a[i]);
        }

        for (int i=1; i<=n; i++) {
            printf("%d D\n", b[i]);
            printf("%d D\n", b[i]);
        }

        for (int i=1; i<=m; i++)
            printf("%d W\n", a[i]);


        for (int i=1; i<=n; i++)
            printf("%d W\n", b[i]);


        for (int i=1; i<=m; i++)
            printf("%d L\n", a[i]);


        for (int i=1; i<=n; i++)
            printf("%d L\n", b[i]);

    }


    return 0;
}
