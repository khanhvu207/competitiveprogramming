#include<bits/stdc++.h>
#define II pair<ll, ll>
#define se second
#define fi first
#define ll long long

using namespace std;

const ll INF = 1000000000+1;
ll n,m,d;
vector<II> adj[1005];

void dijktra(ll srt)
{
    priority_queue <II, vector<II>, greater<II> > q;

    vector <ll> dist(m, INF);

    q.push({0, srt});
    dist[srt] = 0;

    while (!q.empty())
    {
        ll u = q.top().se;
        ll c = q.top().fi;
        q.pop();

        vector< II > :: iterator i;
        for (i = adj[u].begin(); i!= adj[u].end(); ++i)
        {
            ll v = (*i).fi;
            ll w = (*i).se;

            if (dist[v] >= dist[u] + w && w >= c + d)
            {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    if (dist[n-1] == INF)
        dist[n-1] = -1;
    cout << dist[n-1];
}

int main()
{
    freopen("DANANG.INP", "r", stdin);
    freopen("DANANG.OUT", "w", stdout);
    cin>> n>>m>>d;
    int u,v,c;
    for (int i = 0; i < m; ++i)
    {
        cin>>u>>v>>c;
        u--;
        v--;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    dijktra(0);
    return 0;
}
