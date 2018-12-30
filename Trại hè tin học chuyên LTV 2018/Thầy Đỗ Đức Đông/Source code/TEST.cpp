#include <bits/stdc++.h>

using namespace std;

int n, t;
int m[1005], cnt[1005];
vector<int> g[1005];

void Tsort(int L, int R)
{
    if (L == R) return;
    vector<int> d;
    for (int i = L; i <= R; i++) if ((i - L + 1) % 2 == 0) d.push_back(m[i]);
    for (int i = L; i <= R; i++) if ((i - L + 1) & 1) d.push_back(m[i]);
    for (int i = L; i <= R; i++) m[i] = d[i - L];
    int M = (R - L + 1) / 2;
    Tsort(L, L + M - 1);
    Tsort(L + M, R);
}

int main()
{
    freopen("TEST.INP", "r", stdin);
    freopen("TEST.OUT", "w", stdout);

    for (int i = 1; i <= 1000; i++) m[i] = i;
    Tsort(1, 1000);

    cin >> t;
    while (t--)
    {
        for (int i = 0; i <= 1000; i++) g[i].clear();
        cin >> n;
        for (int i = 1, x; i <= n; i++)
        {
            cin >> x;
            g[x].push_back(i);
        }

        for (int i = 0; i <= 1000; i++) if (g[m[i]].size() > 0)
           for (int j = 0; j < (int)g[m[i]].size(); j++) cout << g[m[i]][j] << ' ';
        cout << '\n';
    }
    return 0;
}
