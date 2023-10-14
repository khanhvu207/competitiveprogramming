#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

ll X, d;
vector<ll> res;

int main() {
#ifdef kvutxdy
    freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> X >> d;
    ll cur = 1;
    for (int i = 0; i < 31; ++i) {
        if (((X >> i) & 1) == 0) continue;
        for (int j = 0; j < i; ++j) 
            res.push_back(cur);
        cur += d;
        res.push_back(cur);
        cur += d;
        if ((int)res.size() > 10000) {
            cout << -1;
            return 0;
        }
    }
    cout << (int)res.size() << '\n';
    for (ll i : res) cout << i << ' ';
}