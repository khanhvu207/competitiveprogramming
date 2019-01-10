#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int n, m, snode, edge, low[10015], num[10015], timer = 0, p[100015];
vector<vector<int> > a;
stack<pair<int, int> > stk;

void getAns (int u, int v)
{
    int ecnt = 0;
    set<int> BCC;
    pair<int, int> pivot = make_pair(u, v);
    pair<int, int> top;

    do
    {
        top = stk.top(); stk.pop();
        BCC.insert(top.second);
    } while (top != pivot);
    BCC.insert(u);

    for (set<int>::iterator it = BCC.begin(); it != BCC.end(); ++it)
    {
        for (int i = 0; i < (int)a[*it].size(); ++i)
            if (BCC.find(a[*it][i]) != BCC.end()) ++ecnt;
    }

    snode = max(snode, (int)BCC.size());
    edge = max(edge, ecnt);
}

void dfs (int u)
{
    num[u] = ++timer;
    low[u] = 1000000000;

    for (int i = 0; i < (int)a[u].size(); ++i)
    {
        int v = a[u][i];
        if (v == p[u]) continue;

        if (num[v] > 0)
            low[u] = min(low[u], num[v]);
        else
        {
            p[v] = u;
            stk.push(make_pair(u, v));
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u])
                getAns(u, v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("bicon.inp", "r", stdin);
    freopen("bicon.out", "w", stdout);

    cin >> n >> m;
    a.resize(n + 5);
    for (int i = 0, u, v; i < m; ++i)
        cin >> u >> v,
        a[u].push_back(v),
        a[v].push_back(u);

    for (int i = 1; i <= n; ++i)
        if (num[i] == 0) dfs(i);
    cout << edge / 2 << '\n' << snode; //no. of edge and node in a maximum BCC.
}
