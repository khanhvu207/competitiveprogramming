#include <iostream>
#include <cstdio>
#include <bitset>
#include <queue>
#include <vector>
#define N 200001
#define pb push_back
#define lli long long
#define x first
#define y second
#define vc 1000000000000000000LL
using namespace std;
int D,n,m;
lli d[2][N];
struct kdl{int h[2],c;} e[N];
typedef pair<short,int> td;
vector<td> dsk[N];
typedef pair<lli,td> kdd;
bitset<N> f[2];
void dij(){
    priority_queue<kdd,vector<kdd>,greater<kdd> > q;
    for (int i=1;i<=m;++i) d[0][i]=d[1][i]=vc;
    int u,v;
    short c1,c2;
    for (int i=0,mm=dsk[1].size();i<mm;++i){
        u=dsk[1][i].y,c1=dsk[1][i].x;
        if (e[u].c<d[c1][u])
            d[c1][u]=e[u].c,
            q.push(kdd(d[c1][u],td(c1,u)));
    }
    while(!q.empty()){
        u=q.top().y.y,c1=q.top().y.x,q.pop();
        if (f[c1].test(u)) continue;
        if (e[u].h[c1]==n){
            printf("%lld",d[c1][u]);
            return;
        }
        f[c1].set(u);
        for (int i=0,mm=dsk[e[u].h[c1]].size();i<mm;++i){
            v=dsk[e[u].h[c1]][i].y,c2=dsk[e[u].h[c1]][i].x;
            if (f[c2].test(v)||e[v].c-e[u].c<D) continue;
            if (d[c1][u]+e[v].c<d[c2][v]){
                d[c2][v]=d[c1][u]+e[v].c;
                q.push(kdd(d[c2][v],td(c2,v)));
            }
        }
    }
    printf("-1");
}
int main(){
    freopen("DANANG.inp","r",stdin);
    freopen("DANANG.out","w",stdout);
    scanf("%d%d%d",&n,&m,&D);
    for (int i=1;i<=m;++i)
        scanf("%d%d%d",&e[i].h[0],&e[i].h[1],&e[i].c),
        dsk[e[i].h[0]].pb(td(1,i)),dsk[e[i].h[1]].pb(td(0,i));
    dij();
}
