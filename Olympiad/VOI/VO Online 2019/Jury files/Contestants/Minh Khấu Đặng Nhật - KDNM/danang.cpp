#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair <long long, pair <int, int>> data;

struct Tedge {
    int length, node[2];

    bool operator <(const Tedge &e) const {
        return length < e.length;
    }
} edge[200000];

int n, m, d;
vector <pair <int, int>> a[200015];
priority_queue <data, vector <data>, greater <data>> heap;
bool vis[200000][2];

int main() {
    freopen("danang.inp", "r", stdin);
    freopen("danang.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> d;
    for (int i = 0; i < m; ++i)
        cin >> edge[i].node[0] >> edge[i].node[1] >> edge[i].length,
        a[edge[i].node[0]].push_back({i, 1}),
        a[edge[i].node[1]].push_back({i, 0});
    for (auto p: a[1])
        heap.push({edge[p.first].length, p}),
        vis[p.first][1 - p.second] = true;
    while (!heap.empty()) {
        long long c = heap.top().first;
        int i = heap.top().second.first;
        int u = heap.top().second.second;
        heap.pop();
        if (vis[i][u]) continue;
        vis[i][u] = true;
        if (edge[i].node[u] == n) {
            cout << c; return 0;
        }
        for (auto p: a[edge[i].node[u]])
            if (edge[i].length + d <= edge[p.first].length)
                heap.push({c + edge[p.first].length, p});
    }
    cout << -1;
}
