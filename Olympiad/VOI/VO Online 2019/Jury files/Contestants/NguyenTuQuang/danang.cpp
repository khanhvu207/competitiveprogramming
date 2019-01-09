#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const long long linf = 1e17 + 10;

#define X first
#define Y second

int n, m, diff;
int w[N];
int v[N][2];
int pos[N][2];
vector<int> e[N];
vector<int> coor[N];

ll f[N << 1];

bool minimize(ll &x, ll y) {
    if (x > y) x = y; else return 0;
    return 1;
}
struct BIT{
    vector<ll> a;
    BIT(int n = 0) {
        a = vector<ll>(n + 1, linf);
    }

    void update(int x, ll val) {
        while (x < int(a.size())) {
            minimize(a[x], val); 
            x += x & -x;
        }
    }
    ll get(int x) {
        ll ans = linf;
        while (x) {
            minimize(ans, a[x]);
            x -= x & -x;
        }
        return ans;
    }
}mbit[N];
void prepare() {
    cin >> n >> m >> diff;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y >> w[i];
        if (x == y) {
            i--, m--;
            continue;
        }
        v[i][0] = x, v[i][1] = y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        sort(e[i].begin(), e[i].end(), [](int x, int y){
            return w[x] < w[y];
        });
        mbit[i] = BIT(e[i].size());
        for(int j = 0; j < e[i].size(); j++){
            int idx = e[i][j];
            int dir = v[idx][1] == i;
            pos[idx][dir] = j + 1;
            coor[i].push_back(w[idx]);
        }
    }
}
priority_queue<pair<ll, int>> pq; 

ll &getWeight(int idx, int dir) {
    return f[2 * idx + dir]; 
}
void stabilize(int idx, int dir) {
    int i = pos[idx][dir];
    int x = v[idx][dir];
    ll nw = mbit[x].get(i) + w[idx]; 
    if (minimize(getWeight(idx, dir), nw)) {
        pq.push({-nw, idx * 2 + dir});
    }
}
void optimize(int idx, int dir) {
    int i = pos[idx][dir];
    int x = v[idx][dir];
    int y = v[idx][dir ^ 1];
    int L = lower_bound(coor[y].begin(), coor[y].end(), w[idx] + diff) - coor[y].begin();
    mbit[y].update(L + 1, getWeight(idx, dir));
    stabilize(e[y][L], v[e[y][L]][1] == y);
    if (i < e[x].size())
        stabilize(e[x][i], v[e[x][i]][1] == x);
}
ll solve() {
    fill(f, f + 2 * m + 1, linf);

    mbit[1].update(1, 0);
    stabilize(e[1][0], v[e[1][0]][1] == 1);

    long long ans = linf;
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int idx = cur.Y / 2, dir = cur.Y % 2;
        int x = v[idx][dir];
        int y = v[idx][dir ^ 1];
        if (-cur.X > getWeight(idx, dir)) continue;
        if (y == n) 
            minimize(ans, getWeight(idx, dir));
        optimize(idx, dir);
    }
    if (ans == linf) return -1;
    return ans;
}
int main() {
    freopen("danang.inp", "r", stdin);
    freopen("danang.out", "w", stdout);
    prepare();
    cout << solve();
}
