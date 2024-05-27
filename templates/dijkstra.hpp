int n = r * c;
const int INF = numeric_limits<int>::max();
function<void(int, vector<int>&, vector<int>&)> dijkstra = [&](int st, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    p.assign(n, -1);
    d[st] = 0;
    priority_queue q(greater<>{}, vector<pair<int, int>>{});
    q.emplace(0, st);
    while (!q.empty()) {
        auto [du, u] = q.top();
        q.pop();
        if (du != d[u]) continue;
        for (auto [v, w] : g[u]) {
            if (chMin(d[v], d[u] + w)) {
                p[v] = u;
                q.emplace(d[v], v);
            }
        }
    }
};