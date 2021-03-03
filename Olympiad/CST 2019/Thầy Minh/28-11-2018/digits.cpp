#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

long long a, b, k;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("digits.inp", "r", stdin);
    freopen("digits.out", "w", stdout);

    while (cin >> a >> b >> k)
    {
        if (a > b) swap(a, b);
        if (a == 0)
        {
            if (k == 1)
                cout << 0 << '\n';
            else
            {
                --k;
                bool flag = 0;
                vector<int> res;
                for (long long i = 61; i >= 0; --i)
                {
                    if (k < (1ll << i)) continue;
                    if (k & (1ll << i))
                    {
                        flag = 1;
                        res.push_back(b);
                    } else if (flag && !(k & (1ll << i)))
                        res.push_back(a);
                }
                for (int i = 0; i < (int)res.size(); ++i)
                    cout << res[i];
                cout << '\n';
            }
        } else
        {
            --k;
            vector<int> res;
            for (long long len = 1; len <= 61; ++len)
                if (k >= (1ll << len))
                    k -= (1ll << len);
                else
                {
                    for (long long i = len - 1; i >= 0; --i)
                        res.push_back((k & (1ll << i) ? b : a));
                    break;
                }
            for (int i = 0; i < (int)res.size(); ++i)
                cout << res[i];
            cout << '\n';
        }
    }
}
