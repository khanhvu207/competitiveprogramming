#include <bits/stdc++.h>

#include <ranges>
using namespace std;
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")

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
    vector<pair<pair<int, int>, int>> ra;
    map<int, set<pair<int, int>>> leftEnd;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ra.emplace_back(make_pair(x, y), i);
        leftEnd[y].emplace(x, i);
    } 

    ranges::sort(ra);
    vector<int> res1(n, -1);
    vector<int> res2(n, -1);
    vector<pair<pair<int, int>, int>> rb;
    set<pair<pair<int, int>, int>> s;
    for (int i = 0, l = 1; l <= n; ++l) {
        while (i < n && ra[i].first.first <= l) {
            s.emplace(make_pair(ra[i].first.second, ra[i].first.first), ra[i].second);
            ++i;
        }
        auto it = s.begin();
        auto [y, x] = it->first;
        int id = it->second;
        s.erase(it);
        res1[id] = l;
        res2[id] = l;
        rb.emplace_back(make_pair(x, y), id);
    }

    bool isUnique = true;
    for (int i = 0; i < n; ++i) {
        auto [l, r] = rb[i].first;
        int id = rb[i].second;

        auto it = leftEnd[r].begin();
        if (it->second == id) ++it;
        if (it != leftEnd[r].end() && it->first <= i + 1) {
            isUnique = false;
            swap(res2[id], res2[it->second]);
        }

        leftEnd[r].erase({l, id});
    }

    if (isUnique) {
        cout << "YES" << el;
        for (int x : res1) {
            cout << x << ' ';
        }
        cout << el;
    }
    else {
        cout << "NO" << el;
        for (int x : res1) {
            cout << x << ' ';
        }
        cout << el;
        for (int x : res2) {
            cout << x << ' ' ;
        }
        cout << el;
    }
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
