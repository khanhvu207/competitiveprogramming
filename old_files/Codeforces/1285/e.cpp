// Fck off Mr. sweep line :(

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int N = 1e6;
int n, l[N], r[N], a[N], p[N];
 
void solve() {
    cin >> n;
    vector<int> compressed;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        compressed.push_back(l[i]);
        compressed.push_back(r[i]);
    }
    int left = 1e9, right = 0;
    sort(compressed.begin(), compressed.end());
    for (int i = 0; i < n; ++i) {
        l[i] = lower_bound(compressed.begin(), compressed.end(), l[i]) - compressed.begin() + 1;
        r[i] = lower_bound(compressed.begin(), compressed.end(), r[i]) - compressed.begin() + 1;
        l[i] *= 2;
        r[i] *= 2;
        ++a[l[i]];
        --a[r[i] + 1];
        left = min(left, l[i]);
        right = max(right, r[i]);
    }
    int cnt = 1;
    for (int i = 1; i <= right; ++i) {
        a[i] += a[i - 1];
        if (a[i] == 1 && a[i - 1] != 1) ++p[i];
        p[i] += p[i - 1];
        cnt += (!a[i] && a[i - 1]);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int gaps = p[r[i]] - p[l[i] - 1];
        if (a[r[i]] == 1) --gaps;
        if (a[l[i]] == 1) --gaps;
        // cerr << gaps << '\n';
        ans = max(ans, cnt - 1 + gaps + 1);
    }
    // for (int i = l[3]; i <= r[3]; ++i) cerr << a[i] << ' '; cerr << '\n';
    cout << ans << '\n';
    for (int i = 0; i <= right + 5; ++i) a[i] = p[i] = 0;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}