#include <iostream>
#include <queue>
using namespace std;

int n, m, s, t, f, C;
int r[115][115], p[115];

void augment(int u, int bottleneck)
{
    if (u == s)
    {
        f = bottleneck;
        return;
    } else if (p[u] != -1)
    {
        augment(p[u], min(bottleneck, r[p[u]][u]));
        r[p[u]][u] -= f;
        r[u][p[u]] += f;
    }
}

int maxflow()
{
    int mf = 0;
    while (true)
    {
        f = 0;
        for (int i = 1; i <= n; ++i) p[i] = -1;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int v = 1; v <= n; ++v)
                if (r[u][v] > 0 && p[v] == -1)
                    q.push(v), p[v] = u;
        }
        augment(t, 1e9);
        if (f == 0) break;
        mf += f;
    }
    return mf;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    while (cin >> n)
    {
        if (n < 1) return 0;
        cin >> s >> t >> m;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                r[i][j] = 0;
        for (int i = 0, u, v, c; i < m; ++i)
            cin >> u >> v >> c,
            r[u][v] += c,
            r[v][u] += c;
        cout << "Network " << ++C << '\n';
        cout << "The bandwidth is " << maxflow() << ".\n";
        cout << '\n';
    }
}
