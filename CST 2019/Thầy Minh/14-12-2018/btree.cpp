#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e8;

void inc(int& a, int b) {
    a = (a + b) % MOD;
}

string s, t;
stack <int> oper;
int dp, l, r;

int main() {
    freopen("btree.inp", "r", stdin);
    freopen("btree.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int test; cin >> test;
    while (test--) {
        cin >> s >> t;
        for (; !oper.empty(); oper.pop());
        for (char c: s)
            if (c == 'U' && !oper.empty()) oper.pop();
            else if (c == 'L') oper.push(0);
            else if (c == 'R') oper.push(1);
        dp = l = r = 1;
        for (char c: t)
            if (c == 'U' && !oper.empty())
                oper.top() ? inc(l, 1) : inc(r, 1),
                inc(dp, 1), oper.pop();
            else if (c == 'L') inc(dp, l), inc(r, l);
            else if (c == 'R') inc(dp, r), inc(l, r);
        cout << dp << '\n';
    }
}
