#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int flag[10015];
int n, m, toff, c[1015], d[1015], idle[1015], u, v, t;
vector<pair<int, int> > g[1015];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

int main()
{
    freopen("esea.inp", "r", stdin);
    freopen("esea.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &toff);
    for (int i=0; i<n; i++)
        scanf("%d%d", &c[i+1], &d[i+1]);
    while (scanf("%d%d%d", &u, &v, &t)==3)
        g[u].push_back(make_pair(v, t));
    q.push(make_pair(0, 1));
    idle[1]=-1;
    memset(flag, 0, sizeof flag);
    while (!q.empty())
    {
        pair<int, int> top=q.top(); q.pop();
        int u=top.second;
        if (idle[top.second]>=top.first||top.first>toff) continue;
        flag[top.first+c[u]+1]=1;
        idle[u]=top.first+c[u]+d[u]+2;
        for (int i=0; i<(int)g[u].size(); i++)
            q.push(make_pair(idle[u]+g[u][i].second, g[u][i].first));
    }
    int last;
    for (int i=1; i<=toff; i++)
    {
        if (flag[i]>0) last=i;
        flag[i]+=flag[i-1];
        if (flag[i]>=m)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", last+333);
    return 0;
}
/**
    start at ship #1
    bfs + heap min in chronological order
    iterate from t=1 to t=toff to check no. of flag
**/
