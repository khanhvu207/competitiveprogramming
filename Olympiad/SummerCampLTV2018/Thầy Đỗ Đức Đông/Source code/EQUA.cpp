#include <bits/stdc++.h>

using namespace std;

long long n, k, M, sum = 0, res = 1ll, p[4000005], cnt[4000055] = {0};

void sieve()
{
    memset(p, 0, sizeof p);
    p[1] = 1;
    for(int i = 1;i<=4000000;i++) p[i] = i;
    for (int i = 2; i <= sqrt(4000005); i++) {
        if(p[i] != i) continue;
        for (int j = 2; j <= (4000005 / i); j++) p[i * j] = i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //freopen("EQUA.INP", "r", stdin);
    //freopen("EQUA.OUT", "w", stdout);

    cin >> n >> k >> M;
    for (int i = 1, x; i <= k; i++) cin >> x, sum += (x - 1);
    n -= sum;
    sieve();
    for (int i = n - k + 1; i <= n - 1; i++) {
        int t = i;
        while (t > 1) cnt[p[t]]++, t /= p[t];
    }
    for (int i = 1; i <= k - 1; i++) {
        int t = i;
        while (t > 1) cnt[p[t]]--, t /= p[t];
    }
    for (long long i = 2; i <= 4000000; i++)
        for (int j = 1; j <= cnt[i]; j++) res = ((res % M) * (i % M)) % M;

    cout << res;
    return 0;
}
