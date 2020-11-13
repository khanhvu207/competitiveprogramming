#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define TLE() cerr<<"\nTime elapsed: "<<1000*clock()/CLOCKS_PER_SEC<<"ms.\n";
const ll MOD = 1E9+7;
const ll IINF = 1E18;
const int INF = 1e9;
const double EPS = 1E-9;
const double PI = atan(1.0) * 4.0;
template<class T> T getbit(T s, int i) {return s>>i&1;}
template<class T> void flipbit(T& s, int i) {s^=(1LL<<i);}
constexpr int cntbit(ll x) {return __builtin_popcountll(x);}
constexpr int lg2(ll x) {return __lg(x);} // return int(log2(x))
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a;a=a*a;p>>=1LL;} return res;}

const int N=55;
int n,m,cnt;
int par[N],h[N],lca[25],val[N];
vector<int> adj[N];
vector<pair<int,int>> q;

void dfs(int u,int p=-1){
	for(int v:adj[u])
		if(v!=p){
			par[v]=u;
			h[v]=h[u]+1;
			dfs(v,u);
		}
}

void get_path(int id){
	int u=q[id].fi;
	int v=q[id].se;
	if(h[u]<h[v]) swap(u,v);
	while(h[u]>h[v]){
		u=par[u];
	}
	while(u!=v){
		u=par[u];
		v=par[v];
	}
	lca[id]=u;
}

void go(int u,int p){
	for(int v:adj[u])
		if(v!=p){
			go(v,u);
			val[u]+=val[v];
		}
	if(val[u]>0) ++cnt;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	REP(i,n-1){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	cin>>m;
	REP(i,m){
		int u,v;
		cin>>u>>v;
		q.eb(u,v);
		get_path(i);
	}
	ll res=0;
	REP(mask,1<<m){
		FOR(i,1,n) val[i]=0;
		REP(i,m) 
			if(mask>>i&1){
				int u=q[i].fi;
				int v=q[i].se;
				int x=lca[i];
				++val[u];
				++val[v];
				val[x]-=2;
			}
		cnt=0;
		go(1,-1);
		if(cntbit(mask)&1) res-=fpow(2,n-1-cnt);
		else res+=fpow(2,n-1-cnt);
	}
	cout<<res<<'\n';
}

