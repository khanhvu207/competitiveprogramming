#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAX_SIEVE = 1e6 + 1;
const int N = 1e6 + 1;
int phi[N];
ll f[N], ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<bool> composite(MAX_SIEVE, false);
    vector<int> prime;
    phi[1] = 1;
    for (int i = 2; i < MAX_SIEVE; ++i) {
        if (!composite[i]) {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (int j = 0; j < (int)prime.size() && i * prime[j] < MAX_SIEVE; ++j) {
            composite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } 
            phi[i * prime[j]] = phi[i] * phi[prime[j]];
        }
    }
    for (int i = 0; i < (int)prime.size(); ++i) {
        ll x = prime[i];
        f[x] = phi[x] + x;
        while (x * prime[i] * 1LL < N * 1LL) {
            x *= prime[i];
            for (ll j = 1; j * j <= x * 1LL; j *= prime[i]) {
                f[x] += phi[x / j] * j;
                if (j * j != x) f[x] += phi[j] * x / j;
            }
        }
    }
    ans[1] = f[1] = 0;
    for (int i = 2; i < N; ++i) {
        if (!f[i]) {
            f[i] = 1LL;
            int x = i;
            for (int j = 0; j < (int)prime.size() && prime[j] <= sqrt(x); ++j) {
                if (x % prime[j] != 0) continue;
                int k = 1;
                while (x % prime[j] == 0) x /= prime[j], k *= prime[j];
                f[i] *= f[k] * 1LL;
            }
            if (x > 1) f[i] *= f[x] * 1LL;
        }
        ans[i] = ans[i - 1] + f[i] - i;
    }
    
    while (true) {
        int x;
        cin >> x;
        if (!x) break;
        cout << ans[x] << '\n';
    }
}