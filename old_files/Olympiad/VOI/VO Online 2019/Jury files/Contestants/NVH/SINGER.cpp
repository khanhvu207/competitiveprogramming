#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6423;

int n, d, t, a[N];
void sub1() {
    int res = 0, dem, Min, Max;
    for(int x = 0; x < (1 << n); ++x) {
        for(int i = 0; i < n; ++i) {
            if (x >> i & 1) a[i + 1] = a[i] + 1;
            else a[i + 1] = a[i] - 1;
        }
        dem = 0;
        for(int i = 0; i + d - 1 <= n; ++i) {
            Min = 100; Max = -100;
            for(int j = i; j <= i + d - 1; ++j) Min = min(Min, a[j]), Max = max(Max, a[j]);
            if (Max - Min <= 1) dem++;
        }
        if (dem == t) res++;
    }
    cout << res;
}
int main()
{
    #define file "SINGER"
    freopen(file".INP", "r", stdin); freopen(file".OUT", "w", stdout);
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> d >> t;
    if (n <= 20) sub1();
    return 0;
}
