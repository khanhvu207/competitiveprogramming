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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<tuple<int, int, int>> rank;
    for (int i = 0; i < n; ++i) {
        rank.emplace_back(a[i], i, i);
    }
    ranges::sort(rank);

    int maxPos = -1;
    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i) {
        auto [age, pos, idx] = rank[i];
        // pos = -pos;
        if (maxPos != -1) {
            if (maxPos > pos) {
                res[idx] = maxPos - pos - 1;
            }
        }
        chMax(maxPos, pos);
    }
    
    for (int x : res) {
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
