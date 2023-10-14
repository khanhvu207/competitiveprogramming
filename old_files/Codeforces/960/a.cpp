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
    int cnt[3] = {0};
    for (char c : s) ++cnt[c - 'a'];
    if (!cnt[0] || !cnt[1] || !cnt[2]) {
        cout << "NO";
        return 0;
    }
    if (cnt[2] == cnt[0] || cnt[2] == cnt[1]) {
        for (int i = 0; i < (int)s.size() - 1; ++i) 
            if ((s[i] == 'b' && s[i + 1] == 'a') || (s[i] == 'c' && s[i + 1] == 'a')
                || (s[i] == 'c' && s[i + 1] == 'b')) {
                    cout << "NO";
                    return 0;
                }
        cout << "YES";
        return 0;
    } 
    cout << "NO";
}