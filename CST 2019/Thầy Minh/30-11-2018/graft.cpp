#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, p[20015], d[20015];
vector<int> c[20015], g[20015];
string s;

void dfsSpanningtree()
{
    int u = 1;
    n = 1;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (s[i] == 'd')
        {
            int v = ++n;
            p[v] = u;
            c[u].push_back(v);
            g[u].push_back(v);
            g[v].push_back(u);
            u = v;
        } else
            u = p[u];
    }
}

int diameter()
{
    queue<int> q;
    q.push(1);
    memset(d, -1, sizeof d);
    d[1] = 0;
    int far = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        far = max(far, d[u]);
        for (int i = 0; i < (int)g[u].size(); ++i)
            if (d[g[u][i]] == -1)
            {
                q.push(g[u][i]);
                d[g[u][i]] = d[u] + 1;
            }
    }
    return far;
}

void grafting()
{
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i].empty())
        {
            g[i].push_back(c[i][(int)c[i].size() - 1]);
            g[c[i][(int)c[i].size() - 1]].push_back(i);
            c[i].pop_back();
        }
        if (!c[p[i]].empty())
        {
            g[i].push_back(c[p[i]][(int)c[p[i]].size() - 1]);
            g[c[p[i]][(int)c[p[i]].size() - 1]].push_back(i);
            c[p[i]].pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("graft.inp", "r", stdin);
    freopen("graft.out", "w", stdout);

    while (cin >> s)
    {
        if (s == "#") return 0;
        for (int i = 1; i <= 20005; ++i) g[i].clear(), c[i].clear();
        dfsSpanningtree();
        int a = diameter();
        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 1; i <= n; ++i) reverse(c[i].begin(), c[i].end());
        grafting();
        int b = diameter();
        cout << a << ' ' << b << '\n';
    }
}
