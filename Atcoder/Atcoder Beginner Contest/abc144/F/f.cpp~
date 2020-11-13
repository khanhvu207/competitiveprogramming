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
const double EPS = 1E-12;
const double PI = atan(1.0) * 4.0;
template<class T> T getbit(T s, int i) {return s>>i&1;}
template<class T> void flipbit(T& s, int i) {s^=(1LL<<i);}
constexpr int cntbit(ll x) {return __builtin_popcountll(x);}
constexpr int lg2(ll x) {return __lg(x);} // return int(log2(x))
// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
ll fpow(ll a,ll p){ll res=1LL;while(p){if(p&1LL) res=res*a%MOD;a=a*a%MOD;p>>=1LL;} return res;}

const int N=605;
int n,m;
double e[N],f[N];
vector<int> nxt[N],rev[N];
bool vst[N];

void dp(int u){
	vst[u]=true;
	for(int v:nxt[u])
		if(!vst[v]) dp(v);
	double sum_e=0;
	for(int v:nxt[u])
		sum_e+=e[v];
	double deg=sz(nxt[u]);
	e[u]=sum_e/deg+1.0;
}

void go(int u){
	if(u==1){
		f[u]=1;
		return;
	}
	vst[u]=true;
	for(int v:rev[u]){
		if(!vst[v]) go(v);
		double deg=sz(nxt[v]);
		f[u]+=f[v]/deg;
	}	
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	REP(i,m){
		int u,v;
		cin>>u>>v;
		nxt[u].pb(v);
		rev[v].pb(u);
	}
	memset(vst,false,sizeof vst);
	e[n]=f[n]=0;
	vst[n]=true;
	dp(1);
	memset(vst,false,sizeof vst);
	go(n);
	double res=e[1];
	FOR(u,1,n){
		if(sz(nxt[u])==1) continue;
		double deg=sz(nxt[u]);
		double tmp=e[1];
		double opt=e[u];
		tmp-=f[u]*opt;
		if(deg==1) opt=0;
		else{
			double sum=0;
			for(int v:nxt[u])
				sum+=e[v];
			for(int v:nxt[u])
				opt=fmin(opt,(sum-e[v])/(deg-1.0)+1.0);
		}
		tmp+=f[u]*opt;
		if(fabs(tmp)>EPS) 
			res=fmin(res,tmp);
	}
	cout<<fixed<<setprecision(9)<<res<<'\n';
}

