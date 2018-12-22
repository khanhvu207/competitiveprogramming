#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n, p;
long long k, powx[215], dp[215];
string str;

bool isPalin(const string &s)
{

    if ((int)s.size() == 1) return false;
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("dpalin.inp", "r", stdin);
    freopen("dpalin.out", "w", stdout);

    powx[0] = 1ll;
    for (int i = 1; i <= 200; ++i)
        powx[i] = powx[i - 1] * 26ll;

    while (cin >> str)
    {
        if ((int)str.size() == 1)
        {
            cout << 1 << ' ' << 0 << ' ' << (str[0] - 'a' + 1) << '\n';
            continue;
        }
        for (n = str.length(), p = 0; isPalin(str.substr(0, n));) n = (n + 1) / 2, ++p;
        dp[n + 1] = 0;
        for (int i = n; i >= 1; --i)
            if (i <= (n + 1) / 2) dp[i] = min(26 * dp[i + 1], (long long)1e18);
            else dp[i] = min(dp[i + 1] + 25 * powx[n - i], (long long)1e18);

        k = 1;
        bool palin = true;
        for (int i = 1; i <= n; ++i)
            if (i <= (n + 1) / 2)
                k += (str[i - 1] - 'a') * dp[i + 1];
            else
            {
                k += (str[i - 1] - 'a') * powx[n - i];
                if (palin && str[i - 1] != str[n - i])
                {
                    if (str[i - 1] > str[n - i])
                        k -= powx[n - i] - dp[i + 1];
                    palin = false;
                }
            }
        cout << (int)str.size() << ' ' << p << ' ' << k << '\n';
    }
}
