#include<bits/stdc++.h>
#define maxn 100005
using namespace std;

typedef long long ll;

int n, m, d, c[maxn], stt(0);

ll F[1005][1005];

vector< pair<int,int> > P[maxn];



void Dfs()
{
    priority_queue< pair<ll, pair<int,int> > > Q;

    for(int i=0;i<P[1].size();i++)
    {
        F[P[1][i].first][P[1][i].second] = c[P[1][i].second];
        Q.push( make_pair(-c[P[1][i].second], make_pair(P[1][i].first, P[1][i].second)));
    }

    ll dapan = 1e18;

    while(!Q.empty())
    {
        ll u = -Q.top().first;
        int v = Q.top().second.first;
        int k = Q.top().second.second;
        Q.pop();
        if(v == n)
        {
            dapan = u;
            break;
        }

        if(u > F[v][k]) continue;

        for(int i=0;i<P[v].size();i++)
        {
            int a = P[v][i].first;
            int b = P[v][i].second;

            if(c[b] >= c[k] + d)
            {
                if(F[a][b] > F[v][k] + c[b])
                {
                    F[a][b] = F[v][k] + c[b];
                    Q.push( make_pair(-F[a][b], make_pair(a, b)));
                }
            }
        }
    }

    if(dapan == 1e18) cout << -1;
    else cout << dapan;
}

int main()
{
    freopen("DANANG.inp","r",stdin);
    freopen("DANANG.out","w",stdout);

    cin >> n >> m >> d;

    memset(F, 60, sizeof(F));

    for(int i=1;i<=m;i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ++stt;
        c[stt] = w;
        P[u].push_back( make_pair(v, stt));
        P[v].push_back( make_pair(u, stt));
    }

    Dfs();


}
