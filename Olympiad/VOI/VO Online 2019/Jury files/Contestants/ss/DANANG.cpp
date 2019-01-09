#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
#define all(x) x.begin(),x.end()
#define rep(i,x) for(ll i=0;i<(x);++i)
#define finc(i,a,b) for(ll i=(a);i<=(b);++i)
#define fdec(i,a,b) for(ll i=(a);i>=(b);--i)
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pb push_back
#define x first
#define y second
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
template <typename T> inline void read(T &x) {
    char c;
    bool neg=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-') neg=1, c=getchar();
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(neg) x=-x;
}
template <typename T> inline void write(T x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+48);
}
#define _ putchar(' ')
#define __ putchar('\n')
// -----------------------------------------------------------
const ll N=2e5;
ll n,m,D;
vector<ll> G[N+2];
struct edge{
    ll u,v,w;
    bool operator < (const edge &a) const {
        return w<a.w;
    }
};
#define mp make_pair
vector<edge> E;
bool vst[2*N];
ll F[2*N];
int main(){
    fast_io;
    freopen("danang.inp","r",stdin);
    freopen("danang.out","w",stdout);
    cin>>n>>m>>D; E.resize(m*2);
    rep(i,m){
        cin>>E[i].u>>E[i].v>>E[i].w,E[i+m]=E[i];
        swap(E[i+m].u,E[i+m].v);
    }
    sort(all(E));
    rep(i,(ll)E.size()) G[E[i].u].pb(i);
    memset(F,255,sizeof(F));
    priority_queue<ii,vector<ii>,greater<ii>> H;
    for(auto id:G[1]){
        F[id]=E[id].w;
        H.push(mp(F[id],id));
    }
    G[1].clear();
    while (!H.empty()){
        ll id=H.top().y; H.pop();
        if (vst[id]) continue;
        vst[id]=1;
        ll u=E[id].v;
        if (u==n){
            cout << F[id] << '\n';
            return 0;
        }
        fdec(i,(ll)G[u].size()-1,0){
            ll idv=G[u][i];
            if (E[id].w+D>E[idv].w) break;
            G[u].pop_back();
            if (F[idv]==-1||F[id]+E[idv].w<F[idv]){
                F[idv]=F[id]+E[idv].w;
                H.push(mp(F[idv],idv));
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}







