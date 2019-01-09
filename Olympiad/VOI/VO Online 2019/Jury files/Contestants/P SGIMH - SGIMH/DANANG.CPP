#include "bits/stdc++.h"
using namespace std;
#define maxval          0x3f3f3f3f
int n, m;
long long D, d[200001];
struct data {
    int u;
    long long d, pre;
};
queue<data> Q;
struct edge {
    int v;
    long long c;
};
vector<edge> e[200001];
int main() {
    freopen("DANANG.INP", "r", stdin); freopen("DANANG.OUT", "w", stdout);
    scanf("%d %d %lli", &n, &m, &D);
    while (m--) {
        int u, v;
        long long c;
        scanf("%d %d %lli", &u, &v, &c);
        e[u].push_back({v, c});
        e[v].push_back({u, c});
    }

    for (int i=1; i<=n; i++)
        d[i] = maxval*1LL;

    d[1] = 0LL;
    Q.push({1, d[1], -1LL});

    while (!Q.empty()) {
        int u = Q.front().u;
        long long   du = Q.front().d,
                    pre = Q.front().pre;
        Q.pop();
        if (d[u] != du)
            continue;

        for (size_t i=0; i<e[u].size(); i++) {
            int v = e[u][i].v;
            long long uv = e[u][i].c;

            if (pre + D <= uv && d[v] > d[u] + uv) {
                d[v] = du + uv;
                Q.push({v, d[v], uv});
            }
        }
    }

    if (d[n] == maxval)
        printf("-1");
    else
        printf("%lli", d[n]);

    return 0;
}
