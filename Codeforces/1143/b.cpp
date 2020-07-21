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
    string s;
    cin >> s;
    
    ll res = 1LL, cnt = 1LL, res2 = 1LL;
    for (int i = 0; i < (int)s.size(); ++i) res2 *= s[i] - 48LL;
    for (int i = 0; i < (int)s.size(); ++i) {
        ll tmp = cnt * max(1LL, s[i] - 49LL);
        for (int j = i + 1; j < (int)s.size(); ++j) tmp *= 9LL;
        cnt *= s[i] - 48LL;
        res = max(res, tmp);
    }
    cout << max(res, res2);
}  