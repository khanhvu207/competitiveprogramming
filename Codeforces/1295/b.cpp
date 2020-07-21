#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
#ifdef kvutxdy
    freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> prefix;
        int cntZero = 0, cntOne = 0;
        string s;
        cin >> s;
        ll res = 0LL;
        for (char c : s) {
            if (c == '0') cntZero++;
            else cntOne++;
            prefix.push_back(cntZero - cntOne);
            res += prefix.back() == k;
        }
        if (prefix[n - 1] == 0) {
            if (k == 0 || res > 0) res = -1;
            cout << res << '\n';
            continue;
        }
        if (k == 0) ++res;
        for (int i = 0; i < n; ++i) {
            ll t = k - prefix[i];
            if (t % prefix[n - 1] != 0) continue;
            if (t / prefix[n - 1] > 0) ++res;
        }
        cout << res << '\n';
    }
}