#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const int M = N;
const int64_t INF = 1e18;
const int64_t EDGE_LIMIT = 2e9 + 9;

struct Edge {
    int u, v;
    int64_t cost;

    int get_adj(int node) {
        return u ^ v ^ node;
    }

    bool get_side(int node) {
        return node == v;
    }

    int get_node(bool side) {
        return side ? v : u;
    }

    bool operator < (const Edge &o) const {
        return cost < o.cost;
    }
};

Edge E[M];

struct State {
    int edgeIndex;
    int64_t cost;
    bool side;

    State(int edgeIndex, int64_t cost, bool side):
        edgeIndex(edgeIndex), cost(cost), side(side) {}

    int get_node() {
        return E[edgeIndex].get_node(side);
    }

    bool operator < (const State &o) const {
        return cost > o.cost;
    }
};


vector<int> a[N];
int n, m, DIFF;

void read_input() {
    cin >> n >> m >> DIFF;
    for (int i = 1; i <= m; ++i) {
        cin >> E[i].u >> E[i].v >> E[i].cost;
    }
}

bool incCostAndIndex(const int x, const int y) {
    if (E[x].cost != E[y].cost) return E[x].cost < E[y].cost;
    return x < y;
}

bool incCost(const int x, const int y) {
    return E[x].cost - DIFF < E[y].cost;
}

void prepare() {
    E[m + 1].u = n + 1;
    E[m + 1].v = n;
    E[m + 1].cost = +EDGE_LIMIT;

    m += 1;
    n += 1;

    for (int i = 1; i <= m; ++i) {
        a[E[i].u].push_back(i);
        a[E[i].v].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        sort(a[i].begin(), a[i].end(), incCostAndIndex);
    }
}

int64_t d[M][2], dnode[N];

bool minimize(int64_t &a, int64_t b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

void dijkstra(int source) {
    priority_queue<State> Q;

    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < 2; ++j) {
            d[i][j] = INF;
        }
    }

    for (int i = 1; i <= n; ++i) {
        dnode[i] = INF;
    }

    Q.push(State(a[source][0], 0, E[a[source][0]].get_side(source)));
    d[a[source][0]][E[a[source][0]].get_side(source)] = 0;

    while (!Q.empty()) {
        State u = Q.top(); Q.pop();
        //cerr << "init " << u.edgeIndex << ' ' << u.side << ' ' << u.cost << endl;
        if (u.cost != d[u.edgeIndex][u.side]) continue;

        int u_node = u.get_node();
        //cerr << u_node << ' ' << u.edgeIndex << ' ' << E[u.edgeIndex].cost << ' ' << u.cost << endl;
        // wait
        {
            auto it = upper_bound(a[u_node].begin(), a[u_node].end(), u.edgeIndex, incCostAndIndex);

            if (it != a[u_node].end()) {
                int v_edgeIndex = *it;
                State v(v_edgeIndex, u.cost, E[v_edgeIndex].get_side(u_node));
                if (minimize(d[v.edgeIndex][v.side], v.cost)) {
                    Q.push(v);
                }
            }
        }
        // go away
        {
            int v_node = E[u.edgeIndex].get_node(!u.side);
            auto it = lower_bound(a[v_node].begin(), a[v_node].end(), u.edgeIndex, incCost);
            if (it != a[v_node].end()) {
                int v_edgeIndex = *it;
                //assert(!incCost(v_edgeIndex, u.edgeIndex));
                //cerr << "go away " << u.edgeIndex << ' ' << v_edgeIndex << ' ' << E[u.edgeIndex].cost << ' ' << E[v_edgeIndex].cost << endl;
                State v(v_edgeIndex, u.cost + E[u.edgeIndex].cost, E[v_edgeIndex].get_side(v_node));
                if (minimize(d[v.edgeIndex][v.side], v.cost)) {
                    Q.push(v);
                }
            }
        }
    }

    for (int last = 1; last <= m; ++last) {
        for (int side = 0; side < 2; ++side) {
            minimize(dnode[E[last].get_node(side)], d[last][side]);
        }
    }
}

int64_t solve() {
    dijkstra(1);
    int64_t res = dnode[n - 1];
    if (res >= INF) {
        res = -1;
    }
    return res;
}

int main() {
#ifdef THEMIS
    freopen("DANANG.INP", "r", stdin);
    freopen("DANANG.OUT", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    read_input();
    prepare();
    cout << solve() << '\n';
    return 0;
}