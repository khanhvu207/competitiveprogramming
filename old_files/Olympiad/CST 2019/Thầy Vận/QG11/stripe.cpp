#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define prev adjaksd
const int N = 500015;
const int inf = 1e9;

int n, k;
int dp[N][35];
string s;

int rec(int cur, int prev)
{
    if (dp[cur][prev] != -1) return dp[cur][prev];
    if (cur == n)
        return 0;
    dp[cur][prev] = inf;
    for (int i = 0; i < k; ++i)
        if (i != prev) dp[cur][prev] = min(dp[cur][prev], (i != s[cur] - 'A') + rec(cur + 1, i));
    return dp[cur][prev];
}

void trace(int cur, int prev)
{
    if (cur == n) return;
    int tmp = inf, color;
    for (int i = 0; i < k; ++i)
        if (i != prev)
        {
            if ((i != s[cur] - 'A') + rec(cur + 1, i) < tmp)
            {
                tmp = (i != s[cur] - 'A') + rec(cur + 1, i);
                color = i;
            }
        }
    cout << (char)(color + 'A');
    trace(cur + 1, color);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("stripe.inp", "r", stdin);
    freopen("stripe.out", "w", stdout);

    cin >> n >> k;
    cin >> s;
    memset(dp, -1, sizeof dp);
    cout << rec(0, 30) << '\n';
    trace(0, 30);
}
