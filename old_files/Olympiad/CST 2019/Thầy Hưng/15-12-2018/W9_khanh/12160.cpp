#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int L, R, U, f[15], d[11111];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("12160.inp", "r", stdin);
    freopen("12160.out", "w", stdout);

    int tc = 0;
    while (cin >> L >> R >> U)
    {
        if (!L && !R && !U) return 0;
        for (int i = 0; i < U; ++i) cin >> f[i];

        memset(d, -1, sizeof d);
        queue<int> q;
        q.push(L);
        d[L] = 0;
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            if (u == R) break;
            for (int i = 0; i < U; ++i)
                if (d[(u + f[i]) % 10000] < 0)
                {
                    d[(u + f[i]) % 10000] = d[u] + 1;
                    q.push((u + f[i]) % 10000);
                }
        }
        cout << "Case " << ++tc << ": ";
        if (d[R] < 0)
            cout << "Permanently Locked\n";
        else
            cout << d[R] << '\n';
    }
}
