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
void setMax(T& target, const T& value) {
    if (value > target) {
        target = value;
    }
}

template <typename T>
void setMin(T& target, const T& value) {
    if (value < target) {
        target = value;
    }
}
}  // namespace utils
using namespace utils;

using ll = long long;
using ld = long double;
const char el = '\n';
const bool is_multitest = false;

struct DSU
{
	vector<int> r, p;
	DSU(int n)
	{
		r.resize(n, 1);
		p.resize(n);
		iota(p.begin(), p.end(), 0);
	}

	int getRoot(int u)
	{
		return p[u] == u ? u : p[u] = getRoot(p[u]);
	}

	bool merge(int u, int v)
	{
		u = getRoot(u);
		v = getRoot(v);
		if (u == v) return false;
		if (r[u] > r[v]) r[u] += r[v], p[v] = u;
		else r[v] += r[u], p[u] = v;
		return true;
	}
};


void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<tuple<int, int, ll>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u, --v;
        edges.emplace_back(u, v, w);
    }

    ll res = k;
    vector<bool> select(m, false);
    function<void(int, int)> go = [&](int edgeRemain, int l) {
        if (edgeRemain == 0) {
            // Check MST and minimize answer
            DSU dsu(n);
            ll total = 0;
            for (int i = 0; i < m; ++i) {
                if (select[i]) {
                    auto [u, v, w] = edges[i];
                    dsu.merge(u, v);
                    total = (total + w) % k;
                }
            }

            bool validMST = true;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    if (dsu.getRoot(i) != dsu.getRoot(j)) {
                        validMST = false;
                        break;
                    }
                }
            }

            if (validMST) {
                setMin(res, total);
            }
            return;
        }

        for (int i = l; i < m - edgeRemain + 1; ++i) {
            select[i] = true;
            go(edgeRemain - 1, i + 1);
            select[i] = false;
        }
    };

    go(n-1, 0);
    cout << res << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
