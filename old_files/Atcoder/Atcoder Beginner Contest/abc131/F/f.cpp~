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

struct DSU{
	vector<int> r,p;
	DSU(int n){
		r.resize(n,1);
		p.resize(n);
		iota(p.begin(),p.end(),0);
	}
	int getroot(int u){
		return p[u]==u?u:p[u]=getroot(p[u]);
	}
	bool merge(int u,int v){
		u=getroot(u);
		v=getroot(v);
		if(u==v) return false;
		if(r[u]>r[v]) r[u]+=r[v],p[v]=u;
		else r[v]+=r[u],p[u]=v;
		return true;
	}
};

int n;
ll cntx[2*N+5],cnty[2*N+5];
DSU g(2*N+5);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	REP(i,n){
		int x,y;
		cin>>x>>y;
		y+=N;
		g.merge(x,y);
	}
	FOR(i,1,1e5){
		cntx[g.getroot(i)]++;
		cnty[g.getroot(i+N)]++;
	}
	ll res=0;
	REP(i,2*N+5) res+=cntx[i]*cnty[i];
   	cout<<res-n<<'\n';	
}
// the forth point will form a rectangle with other three
// if point (X, Y) exists, there's an edge between X and Y
// the resulted graph contains multiple connected components, each should form an uncompleted bipartite
// after finite number of operations, we have all CC become completed bipartite
// so, let's use DSU to maintain this connectivity
