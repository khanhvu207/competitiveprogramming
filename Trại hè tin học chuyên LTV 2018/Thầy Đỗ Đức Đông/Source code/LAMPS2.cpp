#include <bits/stdc++.h>

using namespace std;

int n, t, a[3005][3005], g[3005][3005], res[3005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("LAMPS2.INP", "r", stdin);
    freopen("LAMPS2.OUT", "w", stdout);
    cin >> n >> t;
    for (int i = 0, u, v; i < n; i++)
    {
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    for (int i = 1; i <= n; i++) a[i][i] = 1;
    while (t--)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) g[i][j] = a[i][j];
        for (int i = 1, x; i <= n; i++) cin >> x, g[i][0] = 1 - x;
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            int p = 1;
            for (; p <= n; p++) if (g[i][p]) break;
            if (p > n) {
                if (g[i][0]) flag = true;
                else continue;
            }
            if (flag) break;
            for (int j = 1; j <= n; j++) if (j != i && g[j][p])
                for (int k = 0; k <= n; k++) g[j][k] ^= g[i][k];
        }
        int k = 0;
        for (int i = 1; i <= n; i++) if (g[i][0])
            for (int j = 1; j <= n; j++) if (g[i][j])
            {
                k++;
                res[k] = j;
                break;
            }
        if (flag) cout << -1 << '\n';
        else {
            cout << k << ' ';
            for (int i = 1; i <= k; i++) cout << res[i] << ' ';
            cout << '\n';
        }
    }
    return 0;
}
