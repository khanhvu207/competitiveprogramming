#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "../../debug.h"
#else
#define debug(...) 42
#endif

namespace utils {
template <typename T>
bool chMax(T& target, const T& value) {
    if (value > target) {
        target = value;
        return true;
    }
    return false;
}

template <typename T>
bool chMin(T& target, const T& value) {
    if (value < target) {
        target = value;
        return true;
    }
    return false;
}
}  // namespace utils
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> need(p);
    for (int& x : need) {
        cin >> x;
        --x;
    }

    const ll INF = numeric_limits<ll>::max();
    vector d(n, vector<ll>(n, INF));
    for (int u = 0; u < n; ++u) {
        d[u][u] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        chMin(d[u][v], w);
        chMin(d[v][u], w);
    }

    for (int k = 0; k < n; ++k) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                d[u][v] = min(d[u][v], max(d[u][k], d[k][v]));
            }
        }
    }
    
    vector<ll> res(n, 0);
    vector<ll> bestLat(n, INF);
    set<int> chosen;
    for (int i = 0; i < p - 1; ++i) {
        int best = -1;
        ll bestVal = INF;
        for (int candidate = 0; candidate < n; ++candidate) {
            if (chosen.find(candidate) == chosen.end()) {
                ll totalLat = 0;
                for (int u : need) {
                    totalLat += min(d[u][candidate], bestLat[u]);
                }
                if (totalLat < bestVal) {
                    bestVal = totalLat;
                    best = candidate;
                }
            }
        }
        chosen.insert(best);

        // Recompute total latency
        ll sumLat = 0;
        for (int u : need) {
            ll minLat = INF;
            for (int v : chosen) {
                chMin(minLat, d[u][v]);
            }
            chMin(bestLat[u], minLat);
            sumLat += bestLat[u];
        }
        res[i] = sumLat;
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    cout << el;
}

const bool is_multitest = true;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
