#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int n, k; string s;
vector <string> str;

string fix(string s) {
    string res = s, t = "";
    for (int i = 0; i < n - 1; ++i)
        t += s[0], s.erase(0, 1),
        res = min(res, s + t);
    return res;
}

void gen(string s, int k) {
    if (!k) str.push_back(fix(s));
    else {
        string t = "B";
        for (int i = 0; i < n - 1; ++i)
            if (s[i] == 'B') {
                if (t[i] == 'B') t += 'B';
                if (t[i] == 'W') t += 'W';
            }
            else {
                if (t[i] == 'B') t += 'W';
                if (t[i] == 'W') t += 'B';
            }
        if ((t[0] == t[n - 1] && s[n - 1] == 'B') || (t[0] != t[n - 1] && s[n - 1] == 'W')) {
            gen(t, k - 1);
            for (int i = 0; i < n; ++i)
                t[i] == 'B' ? t[i] = 'W' : t[i] = 'B';
            gen(t, k - 1);
        }
    }
}

int main() {
    freopen("circle.inp", "r", stdin);
    freopen("circle.out", "w", stdout);
    cin >> n >> k >> s;
    for (int i = 0; i < k; ++i) {
        string t = s[0] == s[n - 1] ? "B" : "W";
        for (int j = 0; j < n - 1; ++j)
            s[j] == s[j + 1] ? t += 'B' : t += 'W';
        s = t;
    }
    gen(s, k);
    int cnt = 0;
    for (int i = 0; i < str.size(); ++i)
        if (!i || str[i] != str[i - 1]) ++cnt;
    cout << cnt;
}
