/*
ID: khanhvu2
LANG: C++14
TASK: butter
*/
#include <bits/stdc++.h>
using namespace std;

const int inf=1e9;

bool vst[801];
int n, p, c, cow[500], d[801];
vector<pair<int, int>> g[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int dijkstra(int st) {
    for (int i=1; i<=p; ++i) d[i]=inf, vst[i]=false;
    d[st]=0;
    q.push({d[st], st});

    while (!q.empty()) {
        int dist=q.top().first;
        int u=q.top().second;
        q.pop();
        if (dist>d[u]) continue;
        vst[u]=true;
        for (pair<int, int> t:g[u]) {
            if (!vst[t.first]&&dist+t.second<d[t.first]) {
                d[t.first]=dist+t.second;
                q.push({d[t.first], t.first});
            }
        }
    }

    int sum=0;
    for (int i=0; i<n; ++i)
        sum+=d[cow[i]];

    return sum;
}

int main() {
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    cin>>n>>p>>c;
    for (int i=0; i<n; ++i) {
        int x; cin>>x;
        cow[i]=x;
    }

    for (int i=0; i<c; ++i) {
        int u, v, cost;
        cin>>u>>v>>cost;
        g[u].push_back({v, cost});
        g[v].push_back({u, cost});
    }

    int res=inf;
    for (int i=1; i<=p; ++i)
         res=min(res, dijkstra(i));

    cout<<res<<'\n';
    return 0;
}
