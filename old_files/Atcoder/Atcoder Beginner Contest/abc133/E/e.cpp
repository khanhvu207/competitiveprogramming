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
int n,k,deg[N];
vector<int> adj[N];
ll f[N];

ll nPk(int x,int y){
	ll res=f[x];
	res=res*fpow(f[x-y],MOD-2)%MOD;
	return res;
}

ll go(int u,int p=-1){
	ll res;
	if(u!=1) res=nPk(k-2,deg[u]-1);
	else res=nPk(k-1,deg[u]);
	for(int v:adj[u])
		if(v!=p) res=res*go(v,u)%MOD;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	REP(i,n-1){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
		++deg[u];
		++deg[v];
	}	
	FOR(u,1,n)
		if(deg[u]+1>k){
			cout<<0<<'\n';
			return 0;
		}
	f[0]=1;
	FOR(i,1,N-1) f[i]=f[i-1]*i%MOD;
	ll res=k*go(1)%MOD;
	cout<<res<<'\n';
}

