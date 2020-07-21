// Determine a diameter of the tree, let a and b be this diameter's endpoints.
// For every node u lays on the path (a, b), find the furthest node which does not lay on the path (a, b).
// answer is length(a, b) + length(u, c)

#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;
int n, x, y, diameter;
bool mark[MAXN];
vector<int> g[MAXN];

void findDiameter() {
    vector<int> step(MAXN, -1), trace(MAXN);
    int longest = 0;
    queue<int> Q;
    Q.push(1);
    step[1] = 0;
    while (!Q.empty()) {
        int u = Q.front(); 
        Q.pop();
        if (step[u] > longest) {
            longest = step[u];
            x = u;
        }
        for (int v : g[u]) 
            if (step[v] == -1) {
                step[v] = step[u] + 1;
                Q.push(v);
            } 
    }
    for (int i = 1; i <= n; ++i) step[i] = -1;
    Q.push(x);
    trace[x] = -1;
    step[x] = longest = 0;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (step[u] > longest) {
            longest = step[u];
            y = u;
        }
        for (int v : g[u]) 
            if (step[v] == -1) {
                step[v] = step[u] + 1;
                trace[v] = u;
                Q.push(v);
            }
    }
    diameter = longest;
    int t = y;
    mark[t] = true;
    while (trace[t] != -1) {
        t = trace[t];
        mark[t] = true;
    }
}

pair<int, int> furthest(int u) {
    set<int> s;
    int longest = 0, z = 0;
    queue<pair<int, int>> Q;
    Q.push(make_pair(u, 0));
    while (!Q.empty()) {
        int u = Q.front().fi;
        int d = Q.front().se;
        Q.pop();
        if (d > longest) {
            longest = d;
            z = u;
        }
        for (int v : g[u]) 
            if (!mark[v] && s.find(v) == s.end()) {
                s.insert(v);
                Q.push(make_pair(v, d + 1));
            }
    }
    return make_pair(longest, z);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    findDiameter();
    pair<int, int> tmp = {0, 0};
    for (int i = 1; i <= n; ++i) 
        if (mark[i]) {
            pair<int, int> r = furthest(i);
            if (tmp.fi < r.fi) tmp = r;
        }
    if (!tmp.se) {
        for (int i = 1; i <= n; ++i) if (i != x && i != y) {
            tmp.se = i;
            break;
        }
    }
    cout << tmp.fi + diameter << '\n';
    cout << x << ' ' << y << ' ' << tmp.se << '\n';
}