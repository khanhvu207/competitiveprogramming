#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 2005;
int n, root, a[N], ans[N], cnt[N];
vector<int> g[N], v[N];

void dfs(int u) {
    cnt[u] = 1;
    for (int v : g[u]) {
        dfs(v);
        cnt[u] += cnt[v];
    }
    if (a[u] >= cnt[u]) {
        cout << "NO\n";
        exit(0);
    }
    for (int i : g[u]) {
        for (int x : v[i])
            v[u].push_back(x);
    }
    v[u].insert(v[u].begin() + a[u], u);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
            int p;
            cin >> p >> a[i];
            g[p].push_back(i);
            if (!p) root = i;
    }
    dfs(root);
    for (int i = 0; i < n; ++i)
            ans[v[root][i]] = i + 1;
    cout << "YES\n";
	for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';	
}
