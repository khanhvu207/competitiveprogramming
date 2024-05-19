#include <bits/stdc++.h>

#include <ranges>
using namespace std;

#ifdef LOCAL
#include "debug.h"
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
    int n;
    cin >> n;
    stack<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push(x);
    }

    stack<int> b;
    int nextCar = 1;
    bool feasible = true;
    vector<pair<char, char>> res;
    while (!a.empty() || !b.empty()) {
        if (a.empty() && !b.empty() && b.top() != nextCar) {
            feasible = false;
            break;
        }

        while ((!b.empty() && b.top() == nextCar) || (!a.empty() && a.top() == nextCar)) {
            if (!b.empty() && b.top() == nextCar) {
                ++nextCar;
                b.pop();
                res.emplace_back('B', 'C');
            }
            else if (!a.empty() && a.top() == nextCar) {
                ++nextCar;
                a.pop();
                res.emplace_back('A', 'C');
            }
        }
        
        if (!a.empty()) {
            if (a.top() < nextCar) {
                feasible = false;
                break;
            }
            else {
                b.push(a.top());
                // debug("Push", a.top());
                a.pop();
                res.emplace_back('A', 'B');
            }
        }

    }

    if (!feasible) cout << -1 << el;
    else {
        cout << (int)res.size() << el;
        for (auto [x, y] : res) {
            cout << x << ' ' << y << el;
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
