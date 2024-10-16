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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    set<int> vst;
    vector<int> b;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (vst.find(x) == vst.end()) {
            b.push_back(x);
        }
        vst.insert(x);
    }
    
    bool ok = true;
    for (int i = 0; i < (int)b.size(); ++i) {
        ok &= b[i] == a[i];
    }

    cout << (ok ? "YA" : "TIDAK") << el;
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
