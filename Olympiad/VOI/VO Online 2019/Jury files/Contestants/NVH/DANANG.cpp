#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
#define f first
#define s second
const int N = 2e5;
const ll oo = 1e15;

ll n, m, D;
vector <ii> g[N];
struct data {
    ll val, u, e;
    data (ll _val, ll _u, ll _e) : val(_val), u(_u), e(_e) {};
    bool operator < (const data &op) const {
        return val > op.val;
    }
};
priority_queue <data> q;
ii d[N];
int main()
{
    #define file "DANANG"
    freopen(file".INP", "r", stdin); freopen(file".OUT", "w", stdout);
    ios_base :: sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> D;
    for(ll i = 1; i <= m; ++i) {
        ll u, v, c;
        cin >> u >> v >> c;
        g[u].push_back(ii(v, c));
        g[v].push_back(ii(u, c));
    }
    for(ll i = 1; i <= n; ++i) d[i] = ii(oo, oo);
    d[1] = ii(0, 0);
    for(int i = 0; i < g[1].size(); ++i) {
        ll v = g[1][i].f;
        ll c = g[1][i].s;
        d[v] = min(d[v], ii(c, c));
        q.push(data(d[v].f, v, d[v].s));
    }
    while (q.size()) {
        ll du = q.top().val;
        ll u = q.top().u;
        ll pre_min = q.top().e;
//        cout << q.top().val << " " << q.top().u << " " << q.top().e << "\n";
        q.pop();
        if (d[u].f != du) continue;
        if (u == n) return cout << du, 0;
        for(int i = 0; i < g[u].size(); ++i) {
            ll v = g[u][i].f;
            ll c = g[u][i].s;
            if (d[v].f > du + c && pre_min + D <= c) {
                d[v].f = du + c;
                d[v].s = c;
                q.push(data(d[v].f, v, c));
            }
            else {
                if (d[v].f == du + c) {
                    if (c < d[v].s && d[u].s <= c) d[v].s = c;
                }
            }
        }
    }
    cout << -1;
    return 0;
}
