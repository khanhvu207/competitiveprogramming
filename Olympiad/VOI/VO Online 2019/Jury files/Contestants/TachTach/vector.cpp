#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#define M 10000001
#define x first
#define y second
#define pb push_back
using namespace std;
short n,m;
int snt[M],a[M],b[M];
vector<int> ds;
void sang(){
    int nn=round(sqrt(M));
    for (int i=2,j;i<=nn;++i)
    if (!snt[i]){
        snt[i]=i;
        ds.pb(i);
        for (j=i<<1;j<=nn;j+=i) snt[j]=i;
    }
}
void them(int u,int d[]){
    int v;
    while(u>1){
        v=snt[u];
        while(u%v==0) u/=v,++d[v];
    }
}
void nhap(){
    sang();
    int u;
    scanf("%hd",&n);
    for (short i=1;i<=n;++i) scanf("%d",&u),them(u,a);
    scanf("%hd",&m);
    for (short i=1;i<=m;++i) scanf("%d",&u),them(u,b);
}
typedef pair<int,int> td;
vector<td> D,W,L;
void giam2(int u){
    int t=0;
    if (b[u]&1) ++t,++b[u];
    while(((b[u]>>1)+a[u])&1){
        t+=2,b[u]+=2;
    }
    D.pb(td(u,t));
    a[u]+=b[u]>>1;
    W.pb(td(u,b[u]>>1));
}
void giam1(int u){
    if (!a[u]) return;
    if (a[u]&1) giam2(u);
    L.pb(td(u,a[u]>>1));
    a[u]=0;
}
int pw(int u,int c){
    if (!c) return 1;
    int tmp=pw(u,c>>1);
    tmp*=tmp;
    if (c&1) tmp*=u;
    return tmp;
}
vector<char> k2;
vector<int> k1;
void toiuu(const vector<td> &d,char o){
    long long tmp=1;
    for (int i=0,nn=d.size(),u,v;i<nn;++i){
        u=d[i].x,v=d[i].y;
        for (int j=0;j<v;++j){
            if (tmp*u>=M){
                k1.pb(tmp),k2.pb(o);
                tmp=u;
            }else tmp*=u;
        }
    }
    k1.pb(tmp),k2.pb(o);
}
int main(){
    freopen("VECTOR.inp","r",stdin);
    freopen("VECTOR.out","w",stdout);
    nhap();
    for (short i=0,nn=ds.size();i<nn;++i)
        giam1(ds[i]);
    toiuu(D,'D');
    toiuu(W,'W');
    toiuu(L,'L');
    printf("%d\n",int(k1.size()));
    for (int i=0,nn=k1.size();i<nn;++i)
        printf("%d %c\n",k1[i],k2[i]);
}
