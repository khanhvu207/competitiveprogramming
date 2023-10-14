#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<string> word;

int n, res = 0;

void rec (int j, int mask)
{
    if (j != n && mask == (1 << 26) - 1)
    {
        res += (1 << (n - j));
        return;
    }
    if (j == n)
    {
        if (mask == ((1 << 26) - 1)) res++;
        return;
    }
    rec(j + 1, mask);
    for (int i = 0; i < (int)word[j].size(); i++)
        mask |= 1 << ((int)word[j][i] - 97);
    rec(j + 1, mask);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("FONT.INP", "r", stdin);
    freopen("FONT.OUT", "w", stdout);
    cin >> n;
    string s;
    int tmask = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        word.push_back(s);
        for (int j = 0; j < (int)s.size(); j++)
            tmask |= 1 << ((int)s[j] - 97);
    }
    if (tmask != (1 << 26) - 1)
    {
        cout << 0;
        return 0;
    }
    rec(0, 0);
    cout << res;
    return 0;
}
