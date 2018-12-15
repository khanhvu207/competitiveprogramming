#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
const int mod = 1e8;
string s, t;
stack<int> stk;
int dp, l, r;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("btree.inp", "r", stdin);
    freopen("btree.out", "w", stdout);

    int tc;
    cin >> tc;

    while (tc--)
    {
        //string line;
        cin >> s; //getline(cin, line);
        cin >> t; //getline(cin, line);
        while (!stk.empty()) stk.pop();
        for (int i = 1; i < (int)s.size(); ++i)
            if (s[i] == 'U')
                if (!stk.empty()) stk.pop();
            else
                stk.push(s[i] != 'L');

        dp = 1, l = 1, r = 1;

        for (int i = 1; i < (int)t.size(); ++i)
            if (t[i] == 'U')
            {
                if (stk.empty()) continue;
                dp = (dp + 1) % mod;

                if (stk.top())
                    l = (l + 1) % mod;
                else
                    r = (r + 1) % mod;
                stk.pop();

            } else
            if (t[i] == 'L')
                dp = (dp + l) % mod, r = (r + l) % mod;
            else
                dp = (dp + r) % mod, l = (l + r) % mod;

        cout << dp << '\n';
    }
}
