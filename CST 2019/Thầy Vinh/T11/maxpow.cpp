#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
#define prev gacongnghiep
const int N = 2000015;

int tc;
long long n, k;
bool prime[N];
vector<long long> p, d;
map<long long, long long> mp, mx;

void sieve(int x)
{
    for (int i = 2; i <= x; ++i)
        prime[i] = true;
    for (int i = 2; i <= sqrt(x); ++i)
        if (prime[i])
            for (int j = i; j <= x / i; ++j)
                prime[i * j] = false;
    for (long long i = 2; i <= x; ++i)
        if (prime[i])
            p.push_back(i);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("maxpow.inp", "r", stdin);
    freopen("maxpow.out", "w", stdout);
    sieve(1000015);
    cin >> tc;
    while (tc--) {
        d.clear();
        mp.clear();
        mx.clear();
        cin >> n >> k;
        for (int i = 0; i < (int)p.size() && p[i] <= sqrt(k); ++i) {
            long long cnt = 0;
            if (k % p[i] != 0) continue;
            while (k % p[i] == 0ll) {
                ++cnt;
                k /= p[i];
            }
            mp[p[i]] = cnt;
            d.push_back(p[i]);

        }
        if (k > 1) {
            mp[k] = 1ll;
            d.push_back(k);
        }
        for (int i = 0; i < (int)d.size(); ++i) {
            long long cnt = 0, prev = 0;
            long long t = d[i], expo = 1;
            while (n / d[i] >= t)
                t *= d[i], ++expo;
            while (t != 1) {
                cnt = n / t - prev;
                mx[d[i]] += cnt * expo;
                prev = n / t;
                t /= d[i];
                --expo;
            }
        }
        long long res = 1e18;
        for (int i = 0; i < (int)d.size(); ++i)
            res = min(res, mx[d[i]] / mp[d[i]]);
        cout << res << '\n';
    }
}
