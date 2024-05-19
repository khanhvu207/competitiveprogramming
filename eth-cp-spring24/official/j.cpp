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
const bool is_multitest = true;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> pos(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    ll res = (n / 2LL) * (n / 2LL) + (n / 2LL + 1LL) * (n / 2LL - 1LL);
    ll numOps = numeric_limits<ll>::max();

    // Case 1: n/2, ..., n/2+1
    {
        ll curOps = 0;
        vector<int> b = a;

        int countLow = 0;
        for (int i = n-1; i >= 0; --i) {
            countLow += (b[i] <= n/2);
            if (b[i] == n/2) {
                int j = i;
                while (j >= 1 && countLow < n/2) {
                    countLow += (b[j-1] <= n/2);
                    swap(b[j-1], b[j]);
                    --j;
                    ++curOps;
                }
                break;
            }
        }

        int countHigh = 0;
        for (int i = 0; i < n; ++i) {
            countHigh += (b[i] > n/2);
            if (b[i] == n/2+1) {
                int j = i;
                while (j < n-1 && countHigh < n/2) {
                    countHigh += (b[j+1] > n/2);
                    swap(b[j+1], b[j]);
                    ++j;
                    ++curOps;
                }
                break;
            }
        }

        countLow = 0;
        countHigh = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] <= n/2) {
                curOps += max(0, countHigh - countLow);
                ++countLow;
            }
            else {
                curOps += max(0, countLow - countHigh - 1);
                ++countHigh;
            }
        }

        debug("Case 1", curOps);
        setMin(numOps, curOps);
    }

    // Case 2: n/2+1, ..., n/2
    {
        ll curOps = 0;
        vector<int> b = a;

        int countLow = 0;
        for (int i = 0; i < n; ++i) {
            countLow += (b[i] <= n/2);
            if (b[i] == n/2) {
                int j = i;
                while (j < n-1 && countLow < n/2) {
                    countLow += (b[j+1] <= n/2);
                    swap(b[j+1], b[j]);
                    ++j;
                    ++curOps;
                }
                break;
            }
        }

        int countHigh = 0;
        for (int i = n-1; i >= 0; --i) {
            countHigh += (b[i] > n/2);
            if (b[i] == n/2+1) {
                int j = i;
                while (j >= 1 && countHigh < n/2) {
                    countHigh += (b[j-1] > n/2);
                    swap(b[j-1], b[j]);
                    --j;
                    ++curOps;
                }
                break;
            }
        }

        countLow = 0;
        countHigh = 0;
        for (int i = n-1; i >= 0; --i) {
            if (b[i] <= n/2) {
                curOps += max(0, countHigh - countLow);
                ++countLow;
            }
            else {
                curOps += max(0, countLow - countHigh - 1);
                ++countHigh;
            }
        }

        debug("Case 2", curOps);
        setMin(numOps, curOps);
    }

    cout << res << ' ' << numOps << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    if (is_multitest) cin >> t;
    while (t--) solve();
    return 0;
}
