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


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> parent(n+1, -1);
    vector<int> children(n+1);
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        parent[i] = x;
        ++children[x];
    }
    parent[1] = 0;
    ++children[0];

    vector<int> markedChildren(n+1, 0);
    vector<bool> marked(n+1, false); 
    while (q--) {
        int m;
        cin >> m;
        vector<int> a;
        for (int _ = 0; _ < m; ++_) {
            int x;
            cin >> x;
            marked[x] = true;
            ++markedChildren[parent[x]];
            a.push_back(x);
        }

        int res = 0;
        for (int u : a) {
            if (!marked[parent[u]]) {
                ++res;
            }
            res += children[u] - markedChildren[u];
        }
        
        cout << res << el;

        for (int u : a) {
            marked[u] = false;
            markedChildren[parent[u]] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
