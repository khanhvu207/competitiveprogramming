#include <bits/stdc++.h>

#include <ranges>
using namespace std;

#ifdef LOCAL
#include "../../debug.h"
#else
#define debug(...) 42
#endif

namespace utils {
template <typename T, typename... Args>
void setValues(const T& value, T& first, Args&... args) {
    first = value;
    if constexpr (sizeof...(args) > 0) {
        setValues(value, args...);
    }
}

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

struct DSU {
    vector<int> r, p;
    DSU(int n) {
        r.resize(n, 1);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int getRoot(int u) { return p[u] == u ? u : p[u] = getRoot(p[u]); }

    int getSize(int u) { return r[u]; }

    bool merge(int u, int v) {
        u = getRoot(u);
        v = getRoot(v);
        if (u == v) return false;
        if (r[u] > r[v])
            r[u] += r[v], p[v] = u;
        else
            r[v] += r[u], p[u] = v;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n, 0);
    vector<set<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++deg[u];
        ++deg[v];
        g[u].insert(v);
        g[v].insert(u);
    }

    vector<int> big;
    vector<int> small;
    for (int u = 0; u < n; ++u) {
        deg[u] = n - 1 - deg[u];
        if (2 * deg[u] >= n) {
            big.push_back(u);
        } else {
            small.push_back(u);
        }
    }

    DSU dsu(n);
    for (int i = 1; i < (int)big.size(); ++i) {
        dsu.merge(big[0], big[i]);
    }

    for (int u : small) {
        for (int v = 0; v < n; ++v) {
            if (g[u].find(v) == g[u].end()) {
                dsu.merge(u, v);
            }
        }
    }

    set<int> seen;
    vector<int> compSize;
    for (int u = 0; u < n; ++u) {
        int r = dsu.getRoot(u);
        if (seen.find(r) == seen.end()) {
            seen.insert(r);
            compSize.push_back(dsu.getSize(r));
        }
    }

    ranges::sort(compSize);
    cout << (int)compSize.size() << el;
    for (int x : compSize) {
        cout << x << ' ';
    }
    cout << el;
}

const bool is_multitest = false;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
