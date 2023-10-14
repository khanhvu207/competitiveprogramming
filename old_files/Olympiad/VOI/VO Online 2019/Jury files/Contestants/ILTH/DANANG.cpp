// ILTH
#include <bits/stdc++.h>
#define FORU(i,a,b) for(long long i = (a); i<=(b); i++)
#define FORD(i,a,b) for(long long i = (a); i>=(b); i--)
using namespace std;
const int PMTH = 100005;
struct Tdata{
    long long v, cost;
};
vector<Tdata> adj[PMTH];
long long res = LLONG_MAX;
int n, m, D, mark[PMTH];

int DFS(int u, long long cur_cost, long long sum){
    for(auto p : adj[u])
        if (!mark[p.v] && p.cost >= cur_cost){
            mark[p.v] = true;
            if (p.v!=n) DFS(p.v,p.cost + D,sum+p.cost);
            else res = min(res, sum + p.cost);
            mark[p.v] = false;
        }
    return 0;
}

int Tenter(){
    long long u, v, c;
    cin >> n >> m >> D;
    FORU(i,1,m){
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    return 0;
}

int Tsolve(){
    mark[1] = true; DFS(1,0,0);
    if (res == LLONG_MAX) cout << -1;
    else cout << res;
    return 0;
}

int main(){
    freopen("DANANG.INP","r",stdin);
    freopen("DANANG.OUT","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Tenter();
    Tsolve();
    return 0;
}
