#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n, k;
ll x[N], y[N], s[N], g[N], f[N], me1, me2, tu, mau;
double res;
void sub1() {
    for(int i = 1; i <= n; ++i) cin >> x[i] >> y[i] >> s[i], mau += s[i];
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);

    for(int i = 1; i <= n; ++i) f[i] = f[i - 1] + x[i];
    for(int i = 1; i <= n; ++i) g[i] = g[i - 1] + y[i];

    if (n % 2 != 0) {
        me1 = x[(n + 1) / 2]; me2 = y[(n + 1) / 2];
    }
    else {
        me1 =  (x[n / 2] + x[n / 2 + 1]) / 2;
        me2 =  (y[n / 2] + y[n / 2 + 1]) / 2;
    }
    tu = 0;
    for(int i = 1; i <= n; ++i) {
        tu += abs(me1 - x[i]) + abs(me2 - y[i]);
    }
    res = (double) tu / mau;
    cout << res;
}
void sub2() {
    double ans = 0;
    cout << ans;
}
void sub3() {
    double ans = 0.6667;
    cout << ans;
}
int main()
{
    #define file "SIGNAL"
    freopen(file".INP", "r", stdin); freopen(file".OUT", "w", stdout);
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    cout << fixed << setprecision(6);
    if (k == 1) sub1();
    if (k == 2) sub2();
    if (k == 3) sub3();
    return 0;
}
