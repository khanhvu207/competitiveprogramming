#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    map<ll, int> Map;
    while (q--) {
        char type;
        cin >> type;
        if (type == '?') {
            ll mask = 0LL;
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            for (ll i = 0; i < (int)s.size(); ++i)
                if (s[i] == '1') mask |= (1LL << i);
            cout << Map[mask] << '\n';
        }
        else {
            ll x; cin >> x;
            ll mask = 0LL;
            for (ll i = 0; i < 18; ++i) {
                if (x & 1LL) mask |= (1LL << i);
                x /= 10;
            }
            if (type == '+') Map[mask]++;
            else Map[mask]--;
        }
    }
}