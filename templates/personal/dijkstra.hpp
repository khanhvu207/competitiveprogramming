#include <queue>
#include <vector>

namespace GraphAlgo {
using namespace std;

template <class T>
vector<T> shortest_path(const vector<vector<pair<int, T>>> &G, int s) {
    vector<T> d((int)G.size(), numeric_limits<T>::max());
    priority_queue q(greater<>{}, vector<pair<T, int>>{});
    d[s] = 0;
    q.emplace(d[s], s);
    while (!q.empty()) {
        auto [d_u, u] = q.top();
        q.pop();
        if (d_u != d[u]) {
            continue;
        }
        for (auto [v, w] : G[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.emplace(d[v], v);
            }
        }
    }
    return d;
}
}  // namespace GraphAlgo