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
ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%MOD;a=a*a%MOD;p>>=1LL;} return res;}

const int N=1e5+5;
int n,q;
vector<pair<int,pair<int,ll>>> adj[N];
vector<array<int,4>> query;
vector<pair<int,bool>> get_query[N];
int p[25][N],h[N],num[N];
ll tot[N],sum[N],res[N];

void dfs(int u){
	for(auto nxt:adj[u])
		if(nxt.fi!=p[0][u]){
			int v=nxt.fi;
			h[v]=h[u]+1;
			tot[v]=tot[u]+nxt.se.se;
			p[0][v]=u;
			dfs(v);
		}
}

void prepare(){
	memset(p,-1,sizeof p);
	dfs(1);
	for(int i=1;(1<<i)<=n;++i)
		FOR(u,1,n)
			if(p[i-1][u]!=-1)
				p[i][u]=p[i-1][p[i-1][u]];
}

int lca(int u,int v){
	if(h[u]<h[v]) swap(u,v);
	for(int i=log2(h[u])+1;i>=0;--i)
		if(p[i][u]!=-1&&h[p[i][u]]>=h[v]) u=p[i][u];
	if(u==v) return u;
	for(int i=log2(h[u])+1;i>=0;--i)
		if(p[i][u]!=-1&&p[i][v]!=-1&&p[i][u]!=p[i][v])
			u=p[i][u],v=p[i][v];
	return p[0][u];
}

void go(int u){
	for(auto x:get_query[u]){
		int id=x.fi;
		bool isLca=x.se;
		int color=query[id][0];
		ll len=query[id][1];
		ll delta=num[color]*len-sum[color];
		if(!isLca) res[id]+=delta;
		else res[id]-=2*delta;
	}
	for(auto nxt:adj[u])
		if(nxt.fi!=p[0][u]){
			int v=nxt.fi;
			int color=nxt.se.fi;
			ll len=nxt.se.se;
			++num[color];
			sum[color]+=len;
			go(v);
			--num[color];
			sum[color]-=len;
		}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	REP(i,n-1){
		int a,b,c;
		ll d;
		cin>>a>>b>>c>>d;
		adj[a].pb(mp(b,mp(c,d)));
		adj[b].pb(mp(a,mp(c,d)));
	}
	prepare();
	REP(i,q){
		array<int,4> t;
		cin>>t[0]>>t[1]>>t[2]>>t[3];
		query.pb(t);
		get_query[t[2]].pb(mp(i,false));
		get_query[t[3]].pb(mp(i,false));
		int a=lca(t[2],t[3]);
		get_query[a].pb(mp(i,true));
		res[i]=tot[t[2]]+tot[t[3]]-2*tot[a];
	}	
	go(1);
	REP(i,q) cout<<res[i]<<'\n';
}

