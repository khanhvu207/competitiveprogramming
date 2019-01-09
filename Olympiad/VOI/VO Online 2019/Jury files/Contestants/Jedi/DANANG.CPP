#define Link ""

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define TASK "DANANG"

using namespace std;

const int maxn = 2e5 + 10;
int n,m,D;
vector <pair<int,int> > e[maxn];
priority_queue <pair<pair<long long,int>,int>,vector<pair<pair<long long,int>,int> >,greater<pair<pair<long long,int>,int> > > pq;

void Enter()
{
    cin >> n >> m >> D;
    for (;m>0;--m) {
        int u,v,c;
        cin >> u >> v >> c;
        e[u].push_back({c,v});
        e[v].push_back({c,u});
    }
}

void Init()
{
    for (int u=1;u<=n;++u)
        sort(e[u].begin(),e[u].end());
}

void Solve()
{
    pq.push({{0,-1e9},1});
    while (!pq.empty()) {
        long long s = pq.top().first.first;
        int l = pq.top().first.second;
        int u = pq.top().second;
        pq.pop();
        if (u == n) {
            cout << s;
            return;
        }
        while (!e[u].empty()) {
            int l2 = e[u].back().first;
            int v = e[u].back().second;
            if (l + D <= l2) {
                pq.push({{s+l2,l2},v});
                e[u].pop_back();
            }
            else
                break;
        }
    }
    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

#ifdef LHL
    freopen(".INP","r",stdin);
    freopen(".OUT","w",stdout);
#else
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
#endif // LHL

    Enter();
    Init();
    Solve();
}
