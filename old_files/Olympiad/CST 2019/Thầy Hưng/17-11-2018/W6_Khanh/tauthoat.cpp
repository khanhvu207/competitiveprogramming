#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int> > SNode;
int n, k, cost[15][15][35], cycle[15][15], d[15][115], C=0;
bool vst[15][115];
priority_queue<SNode, vector<SNode>, greater<SNode> > q;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("tauthoat.inp", "r", stdin);
    freopen("tauthoat.out", "w", stdout);
    while (cin >> n >> k)
    {
        if (n<1&&k<1) return 0;
        for (int u=1; u<=n; ++u)
        {
            for (int v=1; v<=n; ++v)
                if (v!=u)
                {
                    int m; cin >> m;
                    cycle[u][v]=m;
                    for (int i=0; i<m; ++i)
                        cin >> cost[u][v][i];
                }
        }
        for (int u=1; u<=n; ++u)
            for (int t=1; t<=k; ++t)
                d[u][t]=1e9;
        q.push({0, {1, 0}});
        d[1][0]=0;
        while (!q.empty())
        {
            int c=q.top().first;
            int u=q.top().second.first;
            int day=q.top().second.second;
            q.pop();
            if (c>d[u][day]||day==k) continue;
            vst[u][day]=1;
            for (int v=1; v<=n; ++v)
                if (v!=u&&cost[u][v][day%cycle[u][v]]>0)
                {
                    if (!vst[v][day+1]&&c+cost[u][v][day%cycle[u][v]]<d[v][day+1])
                    {
                        d[v][day+1]=c+cost[u][v][day%cycle[u][v]];
                        q.push({d[v][day+1], {v, day+1}});
                    }
                }
        }
        cout << "Test #" << ++C << '\n';
        if (d[n][k]==1e9)
            cout << "Khong the sap lich bay.\n";
        else
            cout << "Chi phi toi thieu la " << d[n][k] << ".\n";
    }
}
