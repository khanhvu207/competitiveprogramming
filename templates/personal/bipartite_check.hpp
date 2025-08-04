#include <bits/stdc++.h>

namespace GraphAlgo {
using namespace std;

bool dfs(int u, int p, const vector<vector<int>>& g, vector<int>& color) {
    for (int v : g[u]) {
        if (v == p) continue;
        if (color[v] == -1) {
            color[v] = color[u] ^ 1;
            if (!dfs(v, u, g, color)) return false;
        } else if (color[v] == color[u]) {
            return false;
        }
    }
    return true;
}

bool isBipartite(const vector<vector<int>>& g) {
    int n = g.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            color[i] = 0;
            if (!dfs(i, -1, g, color)) return false;
        }
    }
    return true;
}
}  // namespace GraphAlgo