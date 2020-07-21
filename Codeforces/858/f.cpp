// # of episodes per connected components is (# of edges) / 2. 
// https://math.stackexchange.com/questions/2141916/connected-graph-with-an-even-number-of-edges

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, m, timeIn[N], timer;
vector<int> g[N];
vector<tuple<int, int, int>> ans;

bool dfs(int u, int p) {
    timeIn[u] = ++timer;
    vector<int> c;
    for (int v : g[u]) {
        if (v == p) continue;
        if (timeIn[v] && timeIn[v] < timeIn[u]) continue;
        if (dfs(v, u)) c.push_back(v); 
    }
    bool ok = true;
    if ((int)c.size() & 1) {
        ok = false;
        c.push_back(p);
    }
    for (int i = 0; i < (int)c.size(); i += 2) {
        int a = c[i], b = c[i + 1];
        if (b != -1) ans.push_back(tie(a, u, b));
    }
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int u = 1; u <= n; ++u) if (!timeIn[u]) {
        dfs(u, -1);
    }
    cout << (int)ans.size() << '\n';
    for (auto i : ans) {
        int x, y, z;
        tie(x, y, z) = i;
        cout << x << ' ' << y << ' ' << z << '\n';
    }
}