#include <bits/stdc++.h>
#define fi first
#define se second
#define ii pair <long long,long long>
#define ll long long
#define iii pair<ll,ii>
using namespace std;

map<ii,long long> d;
int n,m;
vector<ii> a[200005];
ll D;

void dijk()
{
    priority_queue<iii, vector<iii>,greater<iii> > heap;
    heap.push(iii(0,ii(1,-1e9-1703)));
    while (!heap.empty())
    {
        long long val = heap.top().fi;
        int u = heap.top().se.fi;
        long long trc = heap.top().se.se;
        heap.pop();
        if (d[ii(u,trc)]!=val) continue;
        if (u==n)
        {
            cout << val;
            exit(0);
        }

        for (int i=0; i<a[u].size(); i++)
        {
            int v = a[u][i].fi;
            long long ned = a[u][i].se;
            if (trc + D <=ned && d[ii(v,ned)] > val + ned)
            {
                d[ii(v,ned)] = val + ned;
                heap.push(iii(val+ned,ii(v,ned)));
            }
        }
    }
    cout << -1;
}

int main()
{
    freopen("danang.inp","r",stdin);
    freopen("danang.out","w",stdout);
    cin >> n >> m >> D;
    for (int i=1; i<=m; i++)
    {
        int u,v,k;
        cin >> u >> v >> k;
        a[u].push_back(ii(v,k));
        a[v].push_back(ii(u,k));
        d[ii(u,k)] = 1e18;
        d[ii(v,k)] = 1e18;
    }
    dijk();
    return 0;
}
