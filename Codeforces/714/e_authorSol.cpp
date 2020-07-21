#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 3005;
ll n, a[N], m[N], dp[N], summax, summin;
priority_queue<ll> heapmax;
priority_queue<ll, vector<ll>, greater<ll>> heapmin;

void clearHeaps() {
    summax = summin = 0LL;
    while (!heapmax.empty()) heapmax.pop();
    while (!heapmin.empty()) heapmin.pop();
}

int getMedian(ll x) {
    if (heapmax.empty() && heapmin.empty()) {
        heapmax.push(x);
        summax += x;
        return x;
    }
    ll median = heapmax.size() >= heapmin.size() ? heapmax.top() : heapmin.top();
    if (x < median) heapmax.push(x), summax += x;
    else heapmin.push(x), summin += x;
    if (heapmax.size() > heapmin.size() + 1) {
        heapmin.push(heapmax.top());
        summin += heapmax.top();
        summax -= heapmax.top();
        heapmax.pop();
    } else if (heapmin.size() > heapmax.size() + 1) {
        heapmax.push(heapmin.top());
        summax += heapmin.top();
        summin -= heapmin.top();
        heapmin.pop();
    }
    return heapmax.size() >= heapmin.size() ? heapmax.top() : heapmin.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] -= i;
    }
    for (int i = 1; i <= n; ++i) {
        ll median = getMedian(a[i]);
        dp[i] = median * (ll)heapmax.size() - summax + summin - median * (ll)heapmin.size();
        m[i] = median;
    }
    for (int i = 2; i <= n; ++i) {
        clearHeaps();
        for (int j = i; j >= 2; --j) {
            ll median = getMedian(a[j]);
            if (median < m[j - 1]) continue;
            ll cost = median * (ll)heapmax.size() - summax + summin - median * (ll)heapmin.size();
            if (dp[j - 1] + cost < dp[i]) {
                dp[i] = dp[j - 1] + cost;
                m[i] = median;
            }
        }
    }
    cout << dp[n];
}