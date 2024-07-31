#include <bits/stdc++.h>

#include <ranges>
using namespace std;

#ifdef LOCAL
#include "../../../debug.h"
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
const bool is_multitest = false;


void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;

    ll res = 0;
    for (int _ = 0; _ < 2; ++_) {
        queue<pair<int, int>> q;
        ll s = 0;
        ll last = -1;
        for (int i = n-1; i >= 0; --i) {
            if (a[i] == '1') {
                if (b[i] == '0') {
                    q.emplace(i, s);
                    last = i;
                }
                else if (last != -1) {
                    ll d = last - i;
                    s += d / k;
                    if (d % k) s += 1;
                    last = i;
                }
            }
            else {
                if (b[i] == '1' && !q.empty()) {
                    ll d = last - i;
                    s += d / k;
                    if (d % k) s += 1;
                    res += s;

                    auto [j, _] = q.front();
                    q.pop();
                    swap(a[i], a[j]);
                    last = i;

                    if (!q.empty()) {
                        auto [j, c] = q.front();
                        s -= c;
                    }
                }
            }
        }
        ranges::reverse(a);
        ranges::reverse(b);
    }
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
