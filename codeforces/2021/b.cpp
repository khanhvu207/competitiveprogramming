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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    ranges::sort(a);

    int j = 0;
    map<int, int> cnt;
    for (int i = 0; i < n + 1; ++i) {
        while (j < n and a[j] < i) {
            cnt[a[j] % x] += 1;
            ++j;
        }
        if (j < n and a[j] == i) {
            ++j;
        }
        else {
            if (cnt[i % x] == 0) {
                cout << i << el;
                return;
            }
            cnt[i % x] -= 1;
        }
    }
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
