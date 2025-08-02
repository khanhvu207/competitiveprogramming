#include <bits/stdc++.h>

#include <ranges>
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

pair<vector<int>, ll> transaction(ll M);

// pair<vector<int>, ll> transaction(ll M) {
//     // int N = 100;
//     // vector<ll> prices(N);
//     // for (int i = 0; i < N; ++i) {
//     //     prices[i] = N - i;
//     // }
//     int N = 5;
//     vector<ll> prices = {10, 4, 3, 2, 1};
//     assert(prices[0] > M && "Output isn't correct: Invalid argument");
//     assert(prices[N-1] <= M && "Output isn't correct: Invalid argument");

//     vector<int> items;
//     for (int i = 1; i < N; ++i) {
//         if (prices[i] <= M) {
//             M -= prices[i];
//             items.push_back(i);
//         }
//     }
//     return make_pair(items, M);
// }

void buy_souvenirs(int N, ll P0) {
    vector<int> count(N, 0);
    vector<ll> p(N, -1);
    vector<ll> sum(N, 0);
    p[0] = P0;

    vector<set<int>> depends(N);

    while (true) {
        int unk = 0;
        for (int i = 0; i < N; ++i) {
            unk += p[i] == -1;
        }
        if (unk == 0) break;

        bool flag = false;
        for (int i = N - 1; i >= 0; --i) {
            if (p[i] == -1) flag = true;
            if (p[i] != -1 and flag) {
                auto [items, rem] = transaction(p[i] - 1LL);
                ll tot = p[i] - 1LL - rem;
                debug(i, tot, items);

                for (int x : items) {
                    depends[i + 1].insert(x);
                    ++count[x];
                }

                for (int j = 0; j < N; ++j) {
                    if (p[j] != -1 and depends[i + 1].count(j)) {
                        depends[i + 1].erase(j);
                        tot -= p[j];
                    }
                }

                sum[i + 1] = tot;
                break;
            }

            if ((int)depends[i].size() == 1) {
                int x = *depends[i].begin();
                p[x] = sum[x];
                depends[x].clear();
                for (int j = 0; j < N; ++j) {
                    if (depends[j].count(x)) {
                        depends[j].erase(x);
                        sum[j] -= p[x];
                    }
                }
                break;
            }

            if ((int)depends[i].size() > 1) {
                ll query = sum[i] / (1LL * (int)depends[i].size());
                auto [items, rem] = transaction(query);
                ll tot = query - rem;
                debug(query, tot, items);

                set<int> t;
                for (int x : items) {
                    t.insert(x);
                    ++count[x];
                }

                for (int j = 0; j < N; ++j) {
                    if (p[j] != -1 and t.count(j)) {
                        t.erase(j);
                        tot -= p[j];
                    }
                }

                int x = *t.begin();
                depends[x] = t;
                sum[x] = tot;
                break;
            }
        }
    }

    debug(p);
    debug(count);
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i - count[i]; ++j) {
            transaction(p[i]);
        }
    }
}

// int main() {
//     buy_souvenirs(5, 10);
//     return 0;
// }
