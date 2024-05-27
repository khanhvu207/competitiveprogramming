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

template<typename T>
class fenwick {
public:
  vector<T> a;
  int sz;
  const T inf = numeric_limits<T>::max();
  fenwick(int n) {
    sz = n;
    a.resize(n, 0);
  }
 
  void update(int idx, T val) {
    for (; idx < sz; idx = idx | (idx + 1)) {
        a[idx] += val;
    }
  }
 
  T get(int idx) {
    T res = 0;
    for (; idx >= 0; idx = (idx & (idx + 1)) - 1) {
        res += a[idx];
    }
    return res;
  }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> rank;
    for (int& x : a) {
        cin >> x;
    }
    for (int& x : b) {
        cin >> x;
        rank.push_back(x);
    }

    map<int, int> reindex;
    ranges::sort(rank);
    for (int i = 0; i < (int)rank.size(); ++i) {
        reindex[rank[i]] = i;
    }

    vector<pair<int, int>> gifts;
    for (int i = 0; i < n; ++i) {
        gifts.emplace_back(a[i], reindex[b[i]]);
    }
    ranges::sort(gifts, [&](const auto& l, const auto& r){
        if (l.first == r.first) {
            return l.second > r.second;
        }
        return l.first < r.first;
    });

    ll res = 0;
    fenwick<ll> ft(5000005);
    map<pair<int, int>, ll> countDups;               
    for (int i = n-1; i >= 0; --i) {
        auto [x, y] = gifts[i];
        countDups[{x, y}] += 1;
        ft.update(y, 1LL);
        res += ft.get(y);
        // debug(x, y, ft.get(y));
    }

    for (auto it : countDups) {
        res += it.second * (it.second - 1LL) / 2LL;
    }

    // ll brute_force = 0;
    // for (int i = n-1; i >= 0; --i) {
    //     for (int j = 0; j < n; ++j) {
    //         if (gifts[i].first <= gifts[j].first && gifts[i].second >= gifts[j].second) {
    //             ++brute_force;
    //             debug(gifts[i].first, gifts[i].second, gifts[j].first, gifts[j].second);
    //         }
    //     }
    // }
    // debug(brute_force);

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
