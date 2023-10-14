#include <iostream>
#include <cstdio>
#include <queue>
#define N 1005
#define int64 long long
#define fort(i,a,b) for(int i=a;i<=b;++i)
#define i2 pair<int,int>
#define i3 pair<int64,i2>
using namespace std;

const int64 inf = 1e15;
int n,lock[N][N];
int64 a[N],d[N][N];

int64 Dijkstra()
{
    int u,s,v;
    priority_queue <i3,vector<i3>,greater<i3> > H;
    fort(i,1,n) fort(j,1,n) d[i][j] = inf;
    d[2][1] = a[2];
    H.push(i3(d[2][1],i2(2,1)));
    while (!H.empty()) {
        do{
            u = H.top().second.first;
            s = H.top().second.second;
            H.pop();
        } while (!H.empty() && lock[u][s]);
        if (lock[u][s]) break;
        if (u == n) return d[u][s];
        if (u-s > 0) {
            v = u-s;
            if (d[v][s] > d[u][s]+a[v]) {
                d[v][s] = d[u][s]+a[v];
                H.push(i3(d[v][s],i2(v,s)));
            }
        }
        if (u+s+1 <= n) {
            v = u+s+1;
            if (d[v][s+1] > d[u][s]+a[v]) {
                d[v][s+1] = d[u][s]+a[v];
                H.push(i3(d[v][s+1],i2(v,s+1)));
            }
        }
    }
    return 0;
}
int main()
{
    freopen("JUMP.inp","r",stdin);
    freopen("JUMP.out","w",stdout);
    scanf("%d",&n);
    fort(i,1,n) scanf("%I64d",a+i);
    printf("%I64d",Dijkstra());
}
