#include <bits/stdc++.h>

using namespace std;

struct data{
    int u;
    int j;
    long long w;
};
data e[200010];
struct cmp{
    bool operator() (data a, data b){
        return (a.w>b.w) || (a.w==b.w && e[a.j].w>e[b.j].w);
    }
};
priority_queue <data, vector<data>, cmp> h;
long long n,m,k,u,v,w,res;
vector <int> g[200010];

void sub1(){
    long long d[n+2][m+2];

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            d[i][j]=1e17;
    d[1][0]=0;
    h.push({1,0,0});

    while (h.size()){
        data u=h.top();
        h.pop();
        if (d[u.u][u.j]!=u.w) continue;

        for (int i=0; i<g[u.u].size(); i++){
            int id=g[u.u][i];
            int v= e[id].u-u.u;
            int w= e[id].w;
            if ( w>=e[u.j].w+k && d[v][id]>u.w+w  ) {
                d[v][id]=u.w+w;
                h.push({v,id,d[v][id]});
            }
        }
    }

    res=1e17;
    for (int i=1; i<=m; i++)
        res=min(res,d[n][i]);
}

void sub2(){
    data d[n+2];

    for (int i=1; i<=n; i++)
        d[i].w=1e17;
    d[1].w=0;
    d[1].j=0;
    h.push ({1,0,0});

    while (h.size()){
        data u=h.top();
        h.pop();
        if (d[u.u].w!=u.w) continue;

        for (int i=0; i<g[u.u].size(); i++){
            int id=g[u.u][i];
            int v= e[id].u-u.u;
            int w= e[id].w;
            if ( w>=e[u.j].w+k &&
                 ( (d[v].w>u.w+w) || (d[v].w==u.w+w && e[d[v].j].w>w) )  ) {
                d[v].w=u.w+w;
                d[v].j=id;
                h.push({v,id,d[v].w});
            }
        }
    }

    res=d[n].w;
}

int main(){
    freopen("DANANG.inp","r",stdin);
    freopen("DANANG.out","w",stdout);

    scanf("%lli %lli %lli",&n,&m,&k);
    e[0].w=-1e10;
    for (int i=1; i<=m; i++){
        scanf("%d %d %lli",&u,&v,&w);
        g[u].push_back(i);
        g[v].push_back(i);
        e[i].u=u+v;
        e[i].w=w;
    }

    if ( n*m<=1e7)
        sub1();
    else
        sub2();

    if (res==1e17) cout<<-1;
    else cout<<res;

    return 0;
}
