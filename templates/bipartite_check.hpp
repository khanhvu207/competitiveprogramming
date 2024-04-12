vector<int> color(n, -1);
function<bool(int, int)> dfs = [&](int u, int p) {
    bool flag = true;
    for (int v : g[u]) {
        if (v == p) continue;
        if (color[v] == -1) {
        color[v] = color[u] ^ 1;
        flag &= dfs(v, u);
        }
        else {
        if (color[u] == color[v]) {
            flag = false;
        }
        }
    }
    return flag;
};