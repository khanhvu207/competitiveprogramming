#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 105;
int n, a[N], odd, even, f[N][3][N][N];

int dp(int cur, int prev, int rodd, int reven) {
    if (cur >= n) return 0;
    int& res = f[cur][prev][rodd][reven];
    if (res != -1) return res;
    if (a[cur] != 0) {
        res = (a[cur] % 2 != prev) + dp(cur + 1, a[cur] % 2, rodd, reven);
        return res;
    }
    res = 1e9;
    if (rodd > 0) res = min(res, (prev == 0) + dp(cur + 1, 1, rodd - 1, reven));
    if (reven > 0) res = min(res, (prev == 1) + dp(cur + 1, 0, rodd, reven - 1));
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    even = n / 2;
    odd = n - even;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 0) continue;
        if (a[i] & 1) --odd;
        else --even;
    }
    memset(f, -1, sizeof f);
    cout << min(dp(0, 0, odd, even), dp(0, 1, odd, even));
}