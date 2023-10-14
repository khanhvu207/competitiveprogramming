#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> pref(n);
    ll x = 1e18, ans = -1e18;
    for (int i = 0; i < n; ++i) {
        cin >> pref[i];
        if (i) {
            pref[i] += pref[i - 1];
            ans = max(ans, pref[i] - x);
        }
        if (i != n - 1) ans = max(ans, pref[i]);
        x = min(x, pref[i]);
    }
    cout << (pref[n - 1] > ans ? "YES\n" : "NO\n");
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