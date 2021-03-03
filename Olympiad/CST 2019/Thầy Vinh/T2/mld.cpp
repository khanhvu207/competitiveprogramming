#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int m, n, d, c[815][815], f[815][815], trace[815];
vector <int> a[800];
queue <int> q;
bool no_e[800];

bool find_augment_path(int source, int sink) {
    memset(trace, -1, sizeof trace);
    while (!q.empty()) q.pop();
    trace[sink] = -15; q.push(sink);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: a[u])
            if (c[u][v] - f[u][v] && trace[v] == -1) {
                trace[v] = u; q.push(v);
                if (v == source) return true;
            }
    }
    return false;
}

int max_flow(int source, int sink) {
    while (find_augment_path(source, sink)) {
        int x = 1e7;
        for (int u = source; u != sink; u = trace[u])
            x = min(c[u][trace[u]] - f[u][trace[u]], x);
        for (int u = source; u != sink; u = trace[u])
            f[u][trace[u]] += x, f[trace[u]][u] += x;
    }
    int x = 0;
    for (int v: a[source])
        x += f[v][source];
    return x;
}

int main() {
    freopen("mld.inp", "r", stdin);
    freopen("mld.out", "w", stdout);
    scanf("%d %d %d", &m, &n, &d);
    for (int u, v, x; m--;) {
        scanf("%d %d %d", &u, &v, &x);
        if (u != v) {
            if (!c[u][v])
                a[u].push_back(v),
                a[v].push_back(u);
            c[u][v] += x;
            c[v][u] += x;
        }
    }
    printf("%d\n", max_flow(0, n - 1));
    for (int u; d--;)
        scanf("%d", &u),
        c[u][n] = c[n][u] = m + n,
        a[u].push_back(n),
        a[n].push_back(u),
        no_e[u] = true;
    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
            if (c[u][v]) c[u][v] = 1;
    memset(f, 0, sizeof f);
    printf("%d", max_flow(0, n));
}
