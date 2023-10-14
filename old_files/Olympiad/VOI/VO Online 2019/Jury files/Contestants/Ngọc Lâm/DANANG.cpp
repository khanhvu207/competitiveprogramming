#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

struct triple
{
    int node = 0;
    ll dist = 0;
    ll last_length = 0;

    triple() {}
    triple(int nd, ll d, ll ld)
    {
        node = nd;
        dist = d;
        last_length = ld;
    }

    bool operator < (const triple b) const
    {
        return dist > b.dist;
    }
};

const int MAX_N = 200001;

int N, M;
ll D;
vector<pii> graph[MAX_N];
vector<ll> Dist(MAX_N, INT_MAX);
priority_queue<triple, vector<triple>> heap;

void init_io()
{
    freopen("DANANG.INP", "r", stdin);
    freopen("DANANG.OUT", "w", stdout);
}

void read_input()
{
    scanf("%d %d %lld", &N, &M, &D);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        ll c;
        scanf("%d %d %lld", &u, &v, &c);

        graph[u].push_back(pii(c, v));
        graph[v].push_back(pii(c, u));
    }
}

void solve()
{
    Dist[1] = 0;

    heap.push(triple(1, 0, 0));

    while (!heap.empty())
    {
        triple p = heap.top();
        heap.pop();

        int u = p.node;
        ll du = p.dist;
        ll last = p.last_length;

        if (du != Dist[u]) continue;

        for (pii pv : graph[u])
        {
            int v = pv.second;
            ll uv = pv.first;

            if (last + D <= uv && Dist[v] > du + uv)
            {
                Dist[v] = du + uv;
                heap.push(triple(v, Dist[v], uv));
            }
        }
    }

    if (Dist[N] == INT_MAX) Dist[N] = -1;

    printf("%lld", Dist[N]);
}

int main()
{
    init_io();
    read_input();
    solve();

    return 0;
}
