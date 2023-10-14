// I sort of got the right idea but probably I will think for some more time before looking at the solution.
// Arhh, after took a glance through several friends's solutions, turned out that I was super-dumb last nigh, huhu :<.

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;
 
const int N = 3e5 + 5;
int n, a[N];
ll cnt[N], res = -1e18, k;
vector<ll> g[N];

void dfs(int u, int p) {
    cnt[u] = a[u];
    for (int v : g[u]) 
        if (v != p) {
            dfs(v, u);
            cnt[u] += max(0LL, cnt[v]);
        }    
    res = max(res, cnt[u]);
}

void Go(int u, int p) {
    cnt[u] = a[u];
    for (int v : g[u]) 
        if (v != p) {
            Go(v, u);
            cnt[u] += max(0LL, cnt[v]);
        }
    if (res == cnt[u]) {
        ++k;
        cnt[u] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1;  i <= n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    Go(1, -1);
    cout << res * k << ' ' << k << '\n';
}