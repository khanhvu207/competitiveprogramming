#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n;
long long cnt[5][5] = {0};

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("POINTS.INP", "r", stdin);
    freopen("POINTS.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 0, x, y; i < n; i++)
        scanf("%d%d", &x, &y),
        cnt[x & 1][y & 1]++;
    long long res = 0ll;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            long long C3 = (cnt[i][j] * (cnt[i][j] - 1ll) * (cnt[i][j] - 2ll)) / 6ll;
            long long C2 = ((cnt[i][j] * (cnt[i][j] - 1)) / 2ll) * (n - cnt[i][j]);
            res += C3 + C2;
        }
    printf("%I64d", res);
    return 0;
}
