#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 1e3 + 3;
int n;
ll k1, k2, ans, a[N], b[N];

int main() {
#ifdef kvutxdy
    freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k1 >> k2;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a[i] -= x;
    }
    k1 += k2;
    for (int i = 0; i < k1; ++i) {
        int highest = -1, pos = -1;
        for (int j = 0; j < n; ++j) if (abs(a[j]) > highest) {
            highest = abs(a[j]);
            pos = j;
        }
        if (a[pos] > 0) --a[pos];
        else ++a[pos];
    }
    for (int i = 0; i < n; ++i) ans += a[i] * a[i];
    cout << ans << '\n';
}