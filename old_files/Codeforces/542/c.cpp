/* Observations: 
*   The answer could be a longest path leads to a cycle?
*   Detect those cycles could be done using Tarjan or Kosaraju.
*   Is the point above necessary? Since a path always start a node with outdegree = 1.
*   Oh, actually I have to consider the case that the answer is a cycle itself...
*   
*   UPD:
*       Oops, after failing several testcases, I realized I misunderstood the problem :v
*       We ought to consider the LCM of those cycles's length, plus paths lead to cycles... 
*/
#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
using namespace std;

const int MAXN = 205;
const int inf = 222;
int n, timer, cnt;
ll res, cyclesAns = 1;
int timeIn[MAXN], low[MAXN], color[MAXN], nodeInCycle[MAXN], deg[MAXN];
vector<int> g[MAXN];
stack<int> st;

ll lcm(ll a, ll b) {
    ll t = __gcd(a, b);
    return a * b / t;
}

void dfs(int u) {
    timeIn[u] = low[u] = ++timer;
    st.push(u);
    for (int v : g[u]) {
        if (timeIn[v] > 0) low[u] = min(low[u], timeIn[v]);
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (timeIn[u] == low[u]) {
        ++cnt;
        int v;
        do {
            ++nodeInCycle[cnt];
            v = st.top();
            st.pop();
            color[v] = cnt;
            timeIn[v] = low[v] = inf;
        } while (v != u);
        cyclesAns = lcm(cyclesAns, nodeInCycle[cnt]);
    }
}

int getRes(int u) {
    if (color[u] && nodeInCycle[color[u]] > 1) return 0;
    if (g[u].empty() || g[u][0] == u) return 0;
    return 1 + getRes(g[u][0]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        g[i].push_back(x);
        ++deg[i];
        ++deg[x];
    }   
    for (int i = 1; i <= n; ++i) 
        if (!timeIn[i]) dfs(i);
    res = cyclesAns;
    for (int i = 1; i <= n; ++i) 
        if (deg[i] == 1) {
            ll pathLength = getRes(i);
            if (pathLength <= res) continue;
            ll k = pathLength / cyclesAns;
            if (pathLength % cyclesAns) ++k;
            res = cyclesAns * k;
        }
    cout << res;
}