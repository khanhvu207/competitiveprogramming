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
        bool bad = false;
        string s, t;
        cin >> s >> t;
        vector<int> pos[26];
        int n = s.size(), m = t.size();
        for (int i = 0; i < n; ++i) {
            pos[s[i] - 'a'].push_back(i);
        }
        int cur = -1, res = 0, i = 0;
        while (i < m && !bad) {
            ++res;
            vector<int> p(26, -1);
            cur = -1;
            while (i < m) {
                int c = t[i] - 'a';
                if (pos[c].empty()) {
                    bad = true;
                    break;
                }
                if (p[c] + 1 == (int)pos[c].size()) break;
                while (p[c] + 1 < (int)pos[c].size()) {
                    ++p[c];
                    if (pos[c][p[c]] > cur) break;
                }
                if (pos[c][p[c]] < cur) break;
                cur = max(cur, pos[c][p[c]]);
                ++i;
            }
        }
        if (bad) cout << -1 << '\n';
        else cout << res << '\n';
    }
}