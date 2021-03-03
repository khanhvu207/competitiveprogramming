#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9;
const int M = 5555;
const int N = 115;
#define dec deccccc

int n, m, s, p[N];
bool ok = true;
vector<int> id, delta, dec;
vector<pair<int, pair<int, int> > > E;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("inverse.inp", "r", stdin);
    freopen("inverse.out", "w", stdout);

    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        E.push_back({c, {u, v}});
    }
    sort(E.begin(), E.end());
    for (int i = 1; i <= n; ++i) cin >> p[i];

    delta.resize(m + 5, 0);
    id.resize(n + 5, -1);
    dec.resize(n + 5, inf);

    for (int i = 0; i < m; ++i)
    {
        int u = E[i].second.first;
        int v = E[i].second.second;
        int c = E[i].first;

        for (int j = 0; j < 2; ++j, swap(u, v))
        {
            int change = p[v] - (p[u] + c);
            if (change > 0)
            {
                ok &= delta[i] == 0 || delta[i] == change;
                delta[i] = change;
                dec[v] = 0;
            } else if (-change <= c && -change < dec[v])
            {
                dec[v] = change;
                id[v] = i;
            }
        }
    }
    for (int u = 1; u <= n; ++u)
    {
        if (u == s) continue;
        ok &= dec[u] != inf;
        if (id[u] != -1)
        {
            ok &= delta[id[u]] == 0 || delta[id[u]] == -dec[u];
            delta[id[u]] = -dec[u];
        }
    }
    if (!ok)
        cout << -1 << '\n';
    else
    {
        int sum = 0;
        for (int i = 0; i < m; ++i) sum += abs(delta[i]);
        cout << sum << '\n';
        for (int i = 0; i < m; ++i)
            cout << E[i].second.first << ' ' << E[i].second.second << ' ' << E[i].first + delta[i] << '\n';
    }
}
