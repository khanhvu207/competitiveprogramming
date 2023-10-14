#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
vector<int> g[10015];

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("KOLOTRIA.INP", "r", stdin);
    freopen("KOLOTRIA.OUT", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++)
        scanf("%d%d", &u, &v),
        g[u].push_back(v),
        g[v].push_back(u);
    long long cnt = 0ll;
    for (int i = 1; i <= n; i++)
    {
        int black = (int)g[i].size();
        cnt += black * (n - black - 1ll);
    }
    cnt /= 2ll;
    long long res = (n * (n - 1ll) * (n - 2ll) / 6ll) - cnt;
    printf("%I64d", res);
    return 0;
}
