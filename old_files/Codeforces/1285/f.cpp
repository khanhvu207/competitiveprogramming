#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 1e5 + 1;
int n, cnt[N], mobius[N];
ll ans;
vector<int> p, a[N], divisors[N];

void upd(int x, int v) {
    for (int i : divisors[x]) {
        cnt[i] += v;
    }
}

void sieve(int maxSieve) {
    vector<bool> prime(maxSieve + 1, true);
    for (int i = 2; i <= sqrt(maxSieve); ++i) {
        if (prime[i]) {
            for (int j = 2; j <= maxSieve / i; ++j) {
                prime[i * j] = false;
            }
        }
    }
    for (int i = 2; i <= maxSieve; ++i) if (prime[i]) p.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int maxEle = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int j = 1; j <= sqrt(x); ++j) {
            if (x % j != 0) continue;
            a[j].push_back(x);
            if (x != j * j) a[x / j].push_back(x);
        }
        maxEle = max(maxEle, x);
    }
    sieve(maxEle);
    mobius[1] = 1;
    for (int i = 2; i < maxEle + 1; ++i) {
        int x = i;
        bool square = false;
        int numPrimeDivs = 0;
        for (int j = 0; j < (int)p.size() && p[j] <= sqrt(x); ++j) {
            if (x % p[j] != 0) continue;
            if (x % (p[j] * p[j]) == 0) {
                square = true;
                break;
            } 
            while (x % p[j] == 0) x /= p[j];
            ++numPrimeDivs;
        }
        numPrimeDivs += x > 1;
        if (square) mobius[i] = 0;
        else mobius[i] = (numPrimeDivs & 1) ? -1 : 1;
        for (int j = 1; j <= sqrt(i); ++j) {
            if (i % j != 0) continue;
            divisors[i].push_back(j);
            if (j * j != i) divisors[i].push_back(i / j); 
        }
    }
    divisors[1].push_back(1);
    for (int i = 1; i < maxEle; ++i) {
        for (int& x : a[i]) x /= i;
        sort(a[i].begin(), a[i].end());
        a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
        reverse(a[i].begin(), a[i].end());
        if (i == 1 && a[i].size() == 1) {
            cout << a[i][0];
            return 0;
        }
        stack<int> s;
        int coPrimes = 0;
        for (int& x : a[i]) {
            for (int& j : divisors[x]) {
                coPrimes += mobius[j] * cnt[j];
            }
            while (!s.empty() && coPrimes > 0) {
                if (__gcd(s.top(), x) == 1LL) 
                    ans = max(ans, 1LL * s.top() * x * i), --coPrimes;
                upd(s.top(), -1);
                s.pop();
            }
            s.push(x);
            upd(x, 1);
        }
        while (!s.empty()) {
            upd(s.top(), -1);
            s.pop();
        }
    }
    cout << ans;
}