#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        s = 'A' + s;
        int prev = 0, ans = 0;
        for (int i = 1; i < (int)s.size(); ++i) {
            if (s[i] == 'A') {
                ans = max(ans, i - prev - 1);
                prev = i;
            }
        }
        cout << ans << '\n';
    }
}
