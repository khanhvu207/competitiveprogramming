#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 10015;

int n, k;
int dp[N], f[N];
vector<int> a[N];

void DFS(int u)
{
    if (a[u].empty())
    {
        f[u] = 1;
        dp[u] = 0;
        return;
    }
    f[u] = 1;
    for (int i = 0; i < (int)a[u].size(); ++i)
    {
        DFS(a[u][i]);
        f[u] += f[a[u][i]];
        dp[u] += dp[a[u][i]];
    }
    if (f[u] >= k)
        f[u] = 0, ++dp[u];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("org.inp", "r", stdin);
    freopen("org.out", "w", stdout);

    cin >> k;
    cin >> n;
    for (int u = 2, p; u <= n; ++u)
    {
        cin >> p;
        a[p].push_back(u);
    }
    DFS(1);
    cout << dp[1];
}
