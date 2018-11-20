#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int mod (int a, int k)
{
    if (a>=0) return a%k;
    int q=-a/k;
    a=a+(q+1)*k;
    return a%k;
}

int t, n, k, a[10015];
bool dp[10015][115];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("chiahet.inp", "r", stdin);
    freopen("chiahet.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i=0; i<n; i++)
            cin >> a[i];
        memset(dp, 0, sizeof dp);
        dp[0][mod(a[0], k)]=1;
        for (int i=1; i<n; i++)
            for (int j=0; j<k; j++)
                dp[i][j]|=dp[i-1][mod(j+a[i], k)],
                dp[i][j]|=dp[i-1][mod(j-a[i], k)];
        cout << (dp[n-1][0]?"Yes\n":"No\n");
    }
    return 0;
}
