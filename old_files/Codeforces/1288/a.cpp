#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        bool ok = d <= n;
        for (int i = 1; i * i <= d; ++i) {
            int k = i + (int)ceil((double)d / (i + 1.0));
            if (k <= n) {
                ok = true;
                break;
            }
            int x = d / i;
            k = x + (int)ceil((double)d / (x + 1.0));
            if (k <= n) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}