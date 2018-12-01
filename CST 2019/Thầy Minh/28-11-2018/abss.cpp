#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

string s; int p[2000015];
#define p(x) (p[x + 1000000])

int main() {
    freopen("abss.inp", "r", stdin);
    freopen("abss.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (cin >> s) {
        int f = 0, res = 0;
        memset(p, -1, sizeof p);
        p(0) = 0;
        for (int i = 1; i <= s.length(); ++i) {
            (s[i - 1] == 'A') ? ++f : --f;
            if (p(f - 1) > -1) res = max(res, i - p(f - 1));
            if (p(f) > -1) res = max(res, i - p(f)); else p(f) = i;
            if (p(f + 1) > -1) res = max(res, i - p(f + 1));
        }
        cout << res << '\n';
    }
}
