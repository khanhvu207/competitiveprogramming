/*
    Danang
    Subtask 1: n, m <= 12

    Dijkstra on the graph which has edges of given graphs
    as vertices
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, d;
vector <int> G[1005];
int w[1005][1005];
ll f[1005][1005];
bool dijkstraed[1005][1005];

int main(){
#ifdef THEMIS
	freopen("DANANG.INP", "r", stdin);
	freopen("DANANG.OUT", "w", stdout);
#endif // THEMIS

    iostream::sync_with_stdio(0);

    cin >> n >> m >> d;
    for(int i=1;i<=m;i++){
        int u, v;
        cin >> u >> v;
        cin >> w[u][v]; w[v][u] = w[u][v];
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++)   for(int j=1;j<=n;j++)   f[i][j] = (ll) 1e18;
    f[1][1] = 0;

    typedef tuple<ll,int,int> vertex;   // length, current vertex, adjacent vertex

    priority_queue<vertex, vector<vertex>, greater<vertex> > pq;
    pq.push(make_tuple(0,1,1));
    ll ans = -1;
    while(pq.size()){
        long long dis;
        int u, last;
        tie(dis, u, last)  = pq.top();
        pq.pop();
        if (u == n){
            ans = dis;
            break;
        }
        if (dijkstraed[u][last])   continue;
        dijkstraed[u][last] = 1;

        for(auto v: G[u]){
            if (w[u][last] + d <= w[v][u] && dis + w[v][u] < f[v][u]){
                f[v][u] = dis + w[v][u];
                pq.push(make_tuple(f[v][u],v,u));
            }
        }

    }

    cout << ans;
}
