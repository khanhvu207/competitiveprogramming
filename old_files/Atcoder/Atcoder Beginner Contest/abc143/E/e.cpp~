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

const int N=305;
int n,m,L;
ll w[N][N],f[N][N],g[N][N];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>L;
	FOR(i,1,n)
		FOR(j,1,n){
			if(i==j) continue;
			f[i][j]=g[i][j]=IINF;
		}
	REP(i,m){
		int u,v;
		ll c;
		cin>>u>>v>>c;
		f[u][v]=f[v][u]=c;
	}
	FOR(i,1,n)
		FOR(j,1,n)
			FOR(k,1,n)
				f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
	FOR(i,1,n)
		FOR(j,1,n){
			if(f[i][j]<=L) 
				g[i][j]=min(g[i][j],1LL);
		}
	FOR(i,1,n)
		FOR(j,1,n)
			FOR(k,1,n)
				g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
	int q;
	cin>>q;
	while(q--){
		int u,v;
		cin>>u>>v;
		if(g[u][v]==IINF) cout<<-1<<'\n';
		else cout<<g[u][v]-1<<'\n';
	}
}

