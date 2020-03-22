#include <bits/stdc++.h>

using namespace std;

int n, t;
vector<int> g[50];
map<int, int> state;
vector<int> res;

void optimize1(int c, int mask, int maskC)
{
    if (c == (n / 2))
    {
        state[maskC] = mask;
        return;
    }
    optimize1(c + 1, mask, maskC);
    mask |= (1 << c);
    maskC ^= (1 << c);
    for (int i = 0; i < (int)g[c].size(); i++) maskC ^= (1 << g[c][i]);
    optimize1(c + 1, mask, maskC);
}

void optimize2(int c, int mask, int maskC)
{
    if ((int)res.size() > 1) return;
    if (c == n)
    {
        int target = ((1 << n) - 1) ^ maskC;
        if (state.count(target))
        {
            for (int i = 0; i < n / 2; i++) if (state[target] & (1 << i)) res.push_back(i + 1);
            for (int i = n / 2; i < n; i++) if (mask & (1 << i)) res.push_back(i + 1);
        }
        return;
    }
    optimize2(c + 1, mask, maskC);
    mask |= (1 << c);
    maskC ^= (1 << c);
    for (int i = 0; i < (int)g[c].size(); i++) maskC ^= (1 << g[c][i]);
    optimize2(c + 1, mask, maskC);
}

int main()
{
    freopen("LAMPS.INP", "r", stdin);
    freopen("LAMPS.OUT", "w", stdout);
    cin >> n >> t;
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while (t--)
    {
        int C = 0;
        res.clear();
        state.clear()
        for (int i = 0, x; i < n; i++)
        {
            cin >> x;
            if (x == 1) C |= (1 << i);
        }
        optimize1(0, 0, C);
        optimize2(n / 2, 0, 0);
        int k = res.size();
        if (k < 1) cout << -1;
        else
        {
            cout << k << ' ';
            for (int i = 0; i < k; i++) cout << res[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
