#include <bits/stdc++.h>

using namespace std;

#define fi "danang.inp"
#define fo "danang.out"
#define oo 1e18
#define maxn 200005
#define tr(i,c) for (__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define For(i,a,b) for (int i=a;i<=b;i++)

typedef pair<int64_t,int64_t> II;
set <II> s;
vector <II> a[maxn];
int64_t kc[maxn],dd[maxn],tr[maxn];
int m,n,k;
int64_t d;

void dijkstra(int64_t s1) {
    For(i,1,n) kc[i]=oo,dd[i]=0;
    s.clear();
    dd[s1]=1;
    kc[s1]=0;
    tr[s1]=0;
    s.insert(II(kc[s1],s1));
    while (!s.empty()) {
        II x=*s.begin();
        s.erase(x);
        int u=x.second;
        tr(it,a[u]) {
            int64_t v=(*it).first;
            int64_t l=(*it).second;
                 if (tr[u]+d<=l) {
                    if (kc[v]>kc[u]+l) {
                    if (dd[v]) s.erase(II(kc[v],v));
                    kc[v]=kc[u]+l;
                    dd[v]=1;
                    s.insert(II(kc[v],v));
                    tr[v]=l;
                }
                else if (kc[v]==kc[u]+l)
                     if (tr[v]>l) tr[v]=l;
                }
        }
    }
}

int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    scanf("%d%d%I64d",&n,&m,&d);
    For(i,1,m) {
        int64_t u,v,uv;
        scanf("%I64d%I64d%I64d",&u,&v,&uv);
            a[v].push_back(II(u,uv));
            a[u].push_back(II(v,uv));

    }
    For(i,1,n) a[i].push_back(II(0,0));
    For(i,1,n) tr[i]=oo;
    dijkstra(1);
    if (kc[n]==oo) kc[n]=-1;

    cout<<kc[n];
    For(i,1,n) cout<<tr[i]<<" ";

    return 0;
}


