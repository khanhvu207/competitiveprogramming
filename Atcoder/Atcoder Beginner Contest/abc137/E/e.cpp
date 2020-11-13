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
const ll INF = 1e9;
const double EPS = 1E-9;
const double PI = atan(1.0) * 4.0;
template<class T> T getbit(T s, int i) {return s>>i&1;}
template<class T> void flipbit(T& s, int i) {s^=(1LL<<i);}
constexpr int cntbit(ll x) {return __builtin_popcountll(x);}
constexpr int lg2(ll x) {return __lg(x);} // return int(log2(x))
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%MOD;a=a*a%MOD;p>>=1LL;} return res;}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,m,p;
	cin>>n>>m>>p;
	vector<array<int,3>> edges;
	REP(i,m){
		array<int,3> t;
		REP(j,3) cin>>t[j];
		t[2]=-(t[2]-p);
		edges.pb(t);
	}
	ll old_d;
	vector<ll> d(n+5,INF);
	d[1]=0;
	REP(i,n){
		if(i==n-1)
			old_d=d[n];
		for(auto x:edges){
			int u=x[0];
			int v=x[1];
			int w=x[2];
			if(d[u]!=INF&&d[u]+w<d[v])
				d[v]=(i==n-1)?-INF:d[u]+w;
		}
	}
	REP(i,n-1)
		for(auto x:edges){
			int u=x[0];
			int v=x[1];
			int w=x[2];
			if(d[u]!=INF&&d[u]+w<d[v])
				d[v]=d[u]+w;
		}
	if(old_d>d[n]){
		cout<<-1<<'\n';
		return 0;
	}
	cout<<max(0LL,-d[n])<<'\n';
}

