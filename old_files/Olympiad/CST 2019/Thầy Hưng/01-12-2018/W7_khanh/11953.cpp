#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int t, n, C;
char a[111][111];
bool vst[111][111];

int main()
{
    freopen("11953.inp", "r", stdin);
    freopen("11953.out", "w", stdout);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];
        memset(vst, false, sizeof vst);
        int res = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (a[i][j] != 'x' || vst[i][j]) continue;
                int k = i, len = 0;
                while (a[k + 1][j] != '.' && k + 1 < n)
                    ++k, vst[k][j] = true, ++len;
                k = j;
                if (len < 2) while (a[i][k + 1] != '.' && k + 1 < n)
                    ++k, vst[i][k] = true;
                ++res;
            }
        cout << "Case " << ++C << ": " << res << '\n';
    }
}
