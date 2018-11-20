#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string T, P;
int b[5015], res = 0;

void KMP_backupTable(string X)
{
    int i = 0, j = -1;
    memset(b, 0, sizeof b);
    b[0] = -1;
    while (i < (int)X.size())
    {
        while (j >= 0 && X[i] != X[j]) j = b[j];
        i++, j++;
        b[i] = j;
    }
}

bool KMP_match(string T, string X)
{
    int i = 0, j = 0;
    while (i < (int)T.size())
    {
        while (j >= 0 && T[i] != X[j]) j = b[j];
        i++, j++;
        if (j == (int)X.size())
            return true;
    }
    return false;
}

bool KMP (int p, int len)
{
    if (len < 1) return true;
    string G = P.substr(p, len);
    KMP_backupTable(G);
    return KMP_match(T, G);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("SUBST.INP", "r", stdin);
    freopen("SUBST.OUT", "w", stdout);
    cin >> T >> P;
    int l = 0, r = min((int)T.size(), (int)P.size()), k;
    if (T < P) swap(T, P);
    while (l <= r)
    {
        int m = (l + r) / 2;
        bool flag = 0;
        for (int i = 0; i < (int)P.size() - m + 1; i++)
            if (KMP(i, m))
            {
                l = m + 1;
                k = m;
                flag = 1;
            }
        if (flag) continue;
            else r = m - 1;
    }
    cout << k;
    return 0;
}
