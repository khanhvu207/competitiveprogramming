#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iomanip>
using namespace std;

int n, m, t;
vector<int> g[200];
int s[200][200], l[200][200];
bool vst[200][515];
pair<int, int> p[200][515];
double d[200][515];

struct data
{
    int u;
    int v;
    double time;
    data (int uu, int vv, double timee)
    {
        this -> u = uu;
        this -> v = vv;
        this -> time = timee;
    }
    bool operator < (const data &r) const
    {
        return time > r.time;
    }
};
priority_queue<data> q;

void dijkstra()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= 500; j++)
            d[i][j] = 1000000000.0;
    memset(vst, false, sizeof vst);
    p[0][70] = {-1, -1};
    d[0][70] = 0.0;
    q.push(data(0, 70, 0.0));
    while (!q.empty())
    {
        data T = q.top(); q.pop();
        if (T.time > d[T.u][T.v]) continue;
        vst[T.u][T.v] = true;
        for (int i = 0; i < (int)g[T.u].size(); i++)
        {
            int v = g[T.u][i];
            int spd = s[T.u][v] == 0 ? T.v : s[T.u][v];
            if (!vst[v][spd] && (T.time + (double)((l[T.u][v] * 1.0) / (spd * 1.0)) < d[v][spd]))
            {
                d[v][spd] = T.time + (double)((l[T.u][v] * 1.0) / (spd * 1.0));
                p[v][spd] = {T.u, T.v};
                q.push(data(v, spd, d[v][spd]));
            }
        }
    }
    int best_v;
    double best = 1000000000.0;
    for (int i = 0; i <= 500; i++)
        if (d[t][i] < best)
        {
            best = d[t][i];
            best_v = i;
        }
    vector<int> ans;
    while (p[t][best_v].first != -1)
    {
        ans.push_back(t);
        pair<int, int> tmp = p[t][best_v];
        t = tmp.first;
        best_v = tmp.second;
    }
    reverse(ans.begin(), ans.end());
    cout << 0 << ' ';
    for (int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("SPEED.INP", "r", stdin);
    freopen("SPEED.OUT", "w", stdout);
    cin >> n >> m >> t;
    for (int i = 0, u, v, spd, len; i < m; i++)
    {
        cin >> u >> v >> spd >> len;
        l[u][v] = len;
        s[u][v] = spd;
        g[u].push_back(v);
    }
    dijkstra();

    return 0;
}
