#include <bits/stdc++.h>

#include <ranges>
using namespace std;

template <class T>
vector<T> shortest_path(const vector<vector<pair<int, T>>> &G, int s) {
    vector<T> d((int)G.size(), numeric_limits<T>::max());
    priority_queue q(greater<>{}, vector<pair<T, int>>{});
    d[s] = 0;
    q.emplace(d[s], s);
    while (!q.empty()) {
        auto [d_u, u] = q.top();
        q.pop();
        if (d_u != d[u]) {
            continue;
        }
        for (auto [v, w] : G[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.emplace(d[v], v);
            }
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    
    using ll = long long;
    using edge = tuple<int, int, ll>;
    vector<vector<pair<int, ll>>> G(n);
    vector<edge> e;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
        e.emplace_back(u, v, w);
    }

    vector<int> a(k), b(k), p(k);
    p[0] = 0;
    cin >> a[0] >> b[0];
    --a[0], --b[0];
    for (int i = 1; i < k; ++i) {
        cin >> p[i] >> a[i] >> b[i];
        --a[i], --b[i];
    }

    vector<vector<ll>> fw;
    vector<vector<ll>> bw;
    for (int i = 0; i < k; ++i) {
        fw.emplace_back(shortest_path<ll>(G, a[i]));
        bw.emplace_back(shortest_path<ll>(G, b[i]));
    }

    vector<tuple<ll, edge, bool>> candidates;
    for (auto &[u, v, w] : e) {
        if (fw[0][u] > fw[0][v]) {
            swap(u, v);
        }
        if (fw[0][u] + w + bw[0][v] != fw[0][b[0]]) {
            continue;
        }
        bool ok = false;
        for (int i = 1; i < k; ++i) {
            if (fw[i][u] > fw[i][v]) {
                continue;
            }
            if (fw[i][u] + w + bw[i][v] != fw[i][b[i]]) {
                continue;
            }
            ok |= (fw[0][u] == fw[i][u]) || (p[i] == 1);
        } 
        candidates.emplace_back(fw[0][u], edge(u, v, w), ok);
    }

    ranges::sort(candidates);

    vector<ll> dp(n, 0);
    for (auto [_, ee, ok] : candidates) {
        auto [u, v, w] = ee;
        // cerr << u + 1 << ' ' << v + 1 << ' ' << w << ' ' << ok << '\n';
        dp[v] = max(dp[v], dp[u] + (ok ? w : 0LL));
    }
    cout << dp[b[0]] << '\n';
}

// Verdict 5.74/7.0 (81/100 points)