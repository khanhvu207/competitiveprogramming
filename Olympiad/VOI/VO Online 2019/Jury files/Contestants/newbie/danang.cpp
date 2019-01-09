#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define int64 long long
#define pii pair <int, int>
#define fr first
#define sc second

struct rec{
    int u, i;
    int64 val;
    rec (int _u, int _i, int64 _val){
        u = _u, i = _i, val = _val;
    }
};

struct cmp_heap{
    bool operator () (const rec &a, const rec &b){
        return a.val > b.val;
    }
};

int n, m, d;
vector <pii> e[200005];
vector <int64> c[200005], pos[200005], f[200005];
vector <int64> fe[200005];
priority_queue <rec, vector<rec>, cmp_heap> h;

void input(){
    cin >> n >> m >> d;
    int u, v, w;
    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        e[u].push_back(pii({v, w}));
        e[v].push_back(pii({u, w}));
        c[u].push_back(w);
        c[v].push_back(w);
    }
}

bool cmp(const pii &a, const pii &b){
    return a.sc < b.sc;
}

void init(){
    for (int i = 1; i <= n; i++){
        e[i].push_back(pii({0, -1e18}));
        sort(e[i].begin(), e[i].end(), cmp);
        c[i].push_back(-1e18);
        sort(c[i].begin(), c[i].end());
        pos[i].resize(c[i].size());
        for (int j = 1; j < pos[i].size(); j++){
            if (c[i][j] != c[i][j - 1])
                pos[i][j] = j;
            else pos[i][j] = pos[i][j - 1];
        }
        f[i].resize(c[i].size(), 1e18);
        fe[i].resize(c[i].size() + 1);
    }
}

void up(int i, int j, int64 val){
    if (j >= fe[i][j] || val <= fe[i][j]) return;
    fe[i][j] = val;
    up(i, j + (j & (-j)), val);
}

int64 get(int i, int j){
    if (j == 0) return 1e18;
    return fe[i][j] + get(i, j - (j & (-j)));
}

void dij(){
    for (int i = 2; i <= n; i++)
        up(i, 1, 1e18);
    up(1, 1, 0);
    h.push(rec(1, 0, 0));
    while (!h.empty()){
        int u = h.top().u, i = h.top().i, val = h.top().val;
        h.pop();
        if (u == n && i == 1) break;
        if (val > get(u, i)) continue;
        for (int t = 1; t < e[u].size(); t++)
        if (e[u][t].sc >= c[u][i] + d){
            int v = e[u][t].fr;
            int tmp = pos[v][lower_bound(c[v].begin(), c[v].end(), e[u][t].sc) - c[v].begin()];
            if (val + e[u][t].sc < get(v, tmp)){
                f[v][tmp] = val + e[u][i].sc;
                up(v, tmp, f[v][tmp]);
                h.push(rec(v, tmp, f[v][tmp]));
            }
        }
    }
    cout << get(n, c[n].size() - 1);
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    freopen("danang.inp", "r", stdin);
    freopen("danang.out", "w", stdout);
    input();
    init();
    dij();
    return 0;
}
