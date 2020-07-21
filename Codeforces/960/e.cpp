// Maintain odd and even while doing dfs
// UPD1: Should have check negative modular operations and overflow!
// UPD2: Missing one case! -> from the current node to n - 1 other nodes.

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 2e5 + 5;
const ll MOD = 1e9 + 7;
int n;
ll V[N], odd[N], even[N], cnt[N], res;
vector<int> g[N];

inline ll add(ll a, ll b) {
    (a += MOD) %= MOD;
    (b += MOD) %= MOD;
    return (a + b) % MOD;
}
inline ll mul(ll a, ll b) {
    (a += MOD) %= MOD;
    (b += MOD) %= MOD;
    return (a + MOD) % MOD * (b + MOD) % MOD;
}

void dfs(int u, int p = -1) {
    cnt[u] = 1;
    for (int v : g[u])
        if (v != p) {
            dfs(v, u);
            cnt[u] = add(cnt[u], cnt[v]);
            odd[u] = add(odd[u], even[v] + 1LL);
            even[u] = add(even[u], odd[v]);
        }
}

void go(int u, int p, ll cntOdd, ll cntEven) {
    ll subtree = 1LL;
    ll numOdd = 0LL, numEven = 0LL;
    for (int v : g[u])
        if (v != p) {
            subtree = add(subtree, cnt[v]);
            numOdd = add(numOdd, even[v] + 1LL);
            numEven = add(numEven, odd[v]);
        }
    // Case 1: Ascendants -> Child and reverse~
    res = add(res, mul(cntOdd, mul(-V[u], subtree)));
    res = add(res, mul(cntEven + 1LL, mul(V[u], subtree)));
    res = add(res, mul(numOdd, mul(-V[u], n - subtree + 1)));
    res = add(res, mul(numEven + 1LL, mul(V[u], n - subtree + 1)));
    // Case 2: Child -> Child
    for (int v : g[u]) 
        if (v != p) {
            ll childOdd = even[v] + 1; 
            ll childEven = odd[v];
            res = add(res, mul(childOdd, mul(-V[u], subtree - 1LL - cnt[v])));
            res = add(res, mul(childEven, mul(V[u], subtree - 1LL - cnt[v])));
            go(v, u, numEven + cntEven - odd[v] + 1LL, numOdd + cntOdd - even[v] - 1LL);
        }
}

int main() {
#ifdef kvutxdy
    freopen("C:/Users/khanh/OneDrive/RoadtoPurple/Code/Codeforces/input.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> V[i];
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    go(1, -1, 0, 0);
    for (int i = 1; i <= n; ++i) res = add(res, -V[i]);
    cout << res;
}