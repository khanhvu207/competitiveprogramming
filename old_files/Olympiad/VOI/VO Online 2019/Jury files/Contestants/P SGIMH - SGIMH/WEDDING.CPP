#include "bits/stdc++.h"
using namespace std;
void calc(int n, int m) {
    for (int i=1; i<=n; i++)

}
int main() {
    freopen("WEDDING.INP", "r", stdin); freopen("WEDDING.OUT", "w", stdout);
    scanf("%lli %lli", &k, &MOD);

    for (int i=2; i<k; i++) {
        if (k % i == 0)
            calc(i, k/i);
    }
    return 0;
}
